// load environment variables from .env
require("dotenv").config();

// dependencies, app initialization
const express = require("express");
const exphbs = require("express-handlebars");
const session = require("express-session");
const randomStr = require("randomstring");
const { MongoStore } = require("connect-mongo");
const path = require("path");
const login = require("./routes/login.js");

const app = express();
const HTTP_PORT = process.env.PORT || 3000;
const uri = process.env.MONGODB_URI;
const MongoClient = require("mongodb").MongoClient;
let db;

// app engine setting (configure hbs temple engine)
app.engine(
  ".hbs",
  exphbs.engine({
    extname: ".hbs",
    defaultLayout: false,
  }),
);
// set ".hbs" extension & define views directory
app.set("view engine", ".hbs");
app.set("views", path.join(__dirname, "/views"));

// middleware: serve static files(css,images..)
app.use("/", express.static(path.join(__dirname, "/public")));
// middleware: parse HTLM <form> data -> req.body
app.use(express.urlencoded({ extended: false }));
// middleware: parse JSON -> req.body(object)
app.use(express.json());

// generate secret key if SESSION_SECRET is missing
var strRandom = randomStr.generate();

// trust first proxy (reverse proxy cookies)
app.set("trust proxy", 1);
// configure session (5 min.)
app.use(
  session({
    secret: process.env.SESSION_SECRET || strRandom,
    saveUninitialized: false,
    resave: false,
    store: MongoStore.create({ mongoUrl: uri, dbName: "webbank_demo" }),
    cookie: {
      expires: 5 * 60 * 1000,
    },
  }),
);

// login router: "/" -> "routes/login.js" (#11)
app.use("/", login);

// helper fn.: fetch user's account numbers from MongDB
async function getAccountList(username) {
  const client = await db.collection("clients").findOne({ username: username });
  const accountList = [];
  if (client.chequing) accountList.push(client.chequing);
  if (client.savings) accountList.push(client.savings);
  return accountList;
}

// render banking.hbs
app.get("/banking", async (req, res) => {
  if (!req.session.user) {
    return res.redirect("/");
  }

  const accountList = await getAccountList(req.session.user);

  res.render("banking", {
    inputUsername: req.session.user,
    accountList: accountList,
  });
});

// dispatch selected banking transaction to target view(.hbs)
app.post("/banking", async (req, res) => {
  if (!req.session.user) {
    return res.redirect("/");
  }

  const accountNumber = req.body.accountNumber;
  const transactionType = req.body.transactionType;
  const accountList = await getAccountList(req.session.user);
  const account = await db
    .collection("accounts")
    .findOne({ _id: accountNumber });

  // route to openAccount.hbs
  if (transactionType == "Open an Account") {
    return res.render("openAccount");
  }

  // validate target account exists in DB
  if (!account) {
    return res.render("banking", {
      inputUsername: req.session.user,
      accountList: accountList,
      errorMsg: "Invalid Account Number",
    });
  }

  // route to balance.hbs
  if (transactionType == "Balance") {
    return res.render("balance", {
      accountNumber: accountNumber,
      accountType: account.accountType,
      accountBalance: Number(account.accountBalance).toFixed(2),
    });
  }

  // route to deposit.hbs
  if (transactionType == "Deposit") {
    return res.render("deposit", {
      accountNumber: accountNumber,
    });
  }

  // route to withdrawal.hbs
  if (transactionType == "Withdrawal") {
    return res.render("withdrawal", {
      accountNumber: accountNumber,
    });
  }
});

// handle deposit submission
app.post("/deposit", async (req, res) => {
  if (!req.session.user) {
    return res.redirect("/");
  }

  const accountNumber = req.body.accountNumber;
  const depositAmount = req.body.depositAmount;
  const action = req.body.action;

  if (action == "cancel") {
    return res.redirect("/banking");
  }

  // reject zero, negative inputs
  if (!(Number(depositAmount) > 0)) {
    return res.render("banking", {
      inputUsername: req.session.user,
      accountList: await getAccountList(req.session.user),
      errorMsg: "Invalid Amount",
    });
  }

  const account = await db
    .collection("accounts")
    .findOne({ _id: accountNumber });

  // calculate updated balance (2 decimal)
  const newBalance = Number(
    (Number(account.accountBalance) + Number(depositAmount)).toFixed(2),
  );

  await db
    .collection("accounts")
    .updateOne(
      { _id: accountNumber },
      { $set: { accountBalance: newBalance } },
    );

  return res.redirect("/banking");
});

// handle openAccount creation
app.post("/openAccount", async (req, res) => {
  if (!req.session.user) {
    return res.redirect("/");
  }

  const action = req.body.action;
  const accountType = req.body.accountType;

  if (action == "cancel") {
    return res.redirect("/banking");
  }

  if (action == "submit") {
    const client = await db
      .collection("clients")
      .findOne({ username: req.session.user });

    // prevent duplicate account of same type
    if (
      (accountType == "Chequing" && client.chequing) ||
      (accountType == "Savings" && client.savings)
    ) {
      return res.render("banking", {
        inputUsername: req.session.user,
        accountList: await getAccountList(req.session.user),
        errorMsg: `You already have a ${accountType} account`,
      });
    }

    // generate 7 digit account number
    let newAccountNum = randomStr.generate({ length: 7, charset: "numeric" });

    await db.collection("accounts").insertOne({
      _id: newAccountNum,
      accountType: accountType,
      accountBalance: 0,
    });

    // write new account number to MongoDB
    if (accountType == "Chequing") {
      await db
        .collection("clients")
        .updateOne(
          { username: req.session.user },
          { $set: { chequing: newAccountNum } },
        );
    } else {
      await db
        .collection("clients")
        .updateOne(
          { username: req.session.user },
          { $set: { savings: newAccountNum } },
        );
    }

    const successMsg = `${accountType} Account #${newAccountNum} Created`;
    return res.render("banking", {
      inputUsername: req.session.user,
      accountList: await getAccountList(req.session.user),
      successMsg: successMsg,
    });
  }
});

// handle withdrawal submission (sufficient funds, validate input value, update balance)
app.post("/withdrawal", async (req, res) => {
  if (!req.session.user) {
    return res.redirect("/");
  }

  const accountNumber = req.body.accountNumber;
  const withdrawalAmount = req.body.withdrawalAmount;
  const action = req.body.action;

  if (action == "cancel") {
    return res.redirect("/banking");
  }

  // reject zero, negative inputs
  if (!(Number(withdrawalAmount) > 0)) {
    return res.render("banking", {
      inputUsername: req.session.user,
      accountList: await getAccountList(req.session.user),
      errorMsg: "Invalid Amount",
    });
  }

  const account = await db
    .collection("accounts")
    .findOne({ _id: accountNumber });

  // prevent withdrawal exceeds current balance
  if (Number(withdrawalAmount) > Number(account.accountBalance)) {
    return res.render("banking", {
      inputUsername: req.session.user,
      accountList: await getAccountList(req.session.user),
      errorMsg: "Insufficient Funds",
    });
  }

  // calculate remaining balance (2 decimal)
  const newBalance = Number(
    (Number(account.accountBalance) - Number(withdrawalAmount)).toFixed(2),
  );

  await db
    .collection("accounts")
    .updateOne(
      { _id: accountNumber },
      { $set: { accountBalance: newBalance } },
    );

  return res.redirect("/banking");
});

// middleware: 404 catch-all, if no route matched
app.use((req, res) => {
  res.status(404).send(`Catch-all route`);
});

// IIFE: connct to MongoDB first, then start server
// placed at the bottom to listen for requests
// only after all routes are registered (app.post,app.get...)
(async () => {
  try {
    const client = await MongoClient.connect(uri);
    db = client.db("webbank_demo");
    app.listen(HTTP_PORT, () => {
      console.log(`Listening on port ${HTTP_PORT}`);
    });
  } catch (err) {
    console.log(`err = ${err}`);
  }
})();
