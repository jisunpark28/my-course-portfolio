const HTTP_PORT = process.env.PORT || 3000;

const express = require("express");
const exphbs = require("express-handlebars");
const session = require("express-session");
const randomStr = require("randomstring");
const { MongoStore } = require("connect-mongo");
const path = require("path");
const Login = require("./routes/login.js");
const app = express();

app.engine(
  ".hbs",
  exphbs.engine({
    extname: ".hbs",
    defaultLayout: false,
    layoutsDir: path.join(__dirname, "/views"),
  }),
);

const MongoClient = require("mongodb").MongoClient;
require("dotenv").config();
const uri = process.env.MONGODB_URI;
let db;

app.set("view engine", ".hbs");
app.set("views", path.join(__dirname, "/views"));

app.use("/", express.static(path.join(__dirname, "/public")));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

var strRandom = randomStr.generate();

app.set("trust proxy", 1);
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
app.use("/", Login);

async function getAccountList(username) {
  const client = await db.collection("clients").findOne({ username: username });
  const accountList = [];
  if (client.chequing) accountList.push(client.chequing);
  if (client.savings) accountList.push(client.savings);
  return accountList;
}

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

  if (transactionType == "Open an Account") {
    return res.render("openAccount");
  }

  if (!account) {
    return res.render("banking", {
      inputUsername: req.session.user,
      accountList: accountList,
      errorMsg: "Invalid Account Number",
    });
  }

  if (transactionType == "Balance") {
    return res.render("balance", {
      accountNumber: accountNumber,
      accountType: account.accountType,
      accountBalance: Number(account.accountBalance).toFixed(2),
    });
  }

  if (transactionType == "Deposit") {
    return res.render("deposit", {
      accountNumber: accountNumber,
    });
  }

  if (transactionType == "Withdrawal") {
    return res.render("withdrawal", {
      accountNumber: accountNumber,
    });
  }
});

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

    let newAccountNum = randomStr.generate({ length: 7, charset: "numeric" });

    await db.collection("accounts").insertOne({
      _id: newAccountNum,
      accountType: accountType,
      accountBalance: 0,
    });

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

  if (Number(withdrawalAmount) > Number(account.accountBalance)) {
    return res.render("banking", {
      inputUsername: req.session.user,
      accountList: await getAccountList(req.session.user),
      errorMsg: "Insufficient Funds",
    });
  }

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

app.use((req, res) => {
  res.status(404).send(`Catch-all route`);
});

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
