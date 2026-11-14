const HTTP_PORT = process.env.PORT || 3000;

const express = require("express");
const exphbs = require("express-handlebars");
const session = require("express-session"); //	require express-session to establish session
const randomStr = require("randomstring");
const path = require("path");
const fs = require("fs");
const app = express();

app.engine(
  ".hbs",
  exphbs.engine({
    extname: ".hbs",
    defaultLayout: false,
    layoutsDir: path.join(__dirname, "/views"),
    partialDir: path.join(__dirname, "/views/partials"),
  }),
);

app.set("view engine", ".hbs");
app.set("views", path.join(__dirname, "/views"));

app.use("/", express.static(path.join(__dirname, "/public")));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

var strRandom = randomStr.generate();

app.set("trust proxy", 1);
app.use(
  session({
    secret: strRandom,
    saveUninitialized: false,
    resave: false,
    cookie: {
      expires: 5 * 60 * 1000,
    },
  }),
);

app.get("/", (req, res) => {
  res.render("login");
});

app.get("/login", (req, res) => {
  res.render("login");
});

app.get("/banking", (req, res) => {
  if (!req.session.user) {
    return res.redirect("/");
  }

  res.render("banking", {
    inputUsername: req.session.user,
  });
});

app.post("/login", (req, res) => {
  const inputUsername = req.body.Username;
  const inputPassword = req.body.Password;

  fs.readFile(path.join(__dirname, "user.json"), "utf8", (err, data) => {
    if (err) {
      console.error(err);
      return res.send("File Open Error");
    }

    const dataUsers = JSON.parse(data);

    if (dataUsers[inputUsername] == undefined) {
      return res.render("login", {
        errorMsg: "Not a registered username",
        username: inputUsername,
        password: inputPassword,
      });
    }

    if (dataUsers[inputUsername] !== inputPassword) {
      return res.render("login", {
        errorMsg: "Invalid password",
        username: inputUsername,
        password: inputPassword,
      });
    }
    req.session.user = inputUsername;

    res.render("banking", { inputUsername: inputUsername });
  });
});

app.post("/banking", (req, res) => {
  if (!req.session.user) {
    return res.redirect("/");
  }

  const accountNumber = req.body.accountNumber;
  const transactionType = req.body.transactionType;

  fs.readFile(
    path.join(__dirname, "accounts.json"),
    "utf8",
    function (err, data) {
      if (err) {
        console.error(err);
        return res.send("File Open Error");
      }

      const dataAccounts = JSON.parse(data);

      if (transactionType == "Balance") {
        const account = dataAccounts[accountNumber];

        if (!account) {
          return res.render("banking", {
            inputUsername: req.session.user,
            errorMsg: "Invalid Account Number",
          });
        }

        return res.render("balance", {
          accountNumber: accountNumber,
          accountType: account.accountType,
          accountBalance: Number(account.accountBalance),
        });
      }

      if (transactionType == "Deposit") {
        const account = dataAccounts[accountNumber];

        if (!account) {
          return res.render("banking", {
            inputUsername: req.session.user,
            errorMsg: "Invalid Account Number",
          });
        }

        return res.render("deposit", {
          accountNumber: accountNumber,
        });
      }

      if (transactionType == "Open an Account") {
        return res.render("openAccount");
      }

      if (transactionType == "Withdrawal") {
        const account = dataAccounts[accountNumber];

        if (!account) {
          return res.render("banking", {
            inputUsername: req.session.user,
            errorMsg: "Invalid Account Number",
          });
        }

        return res.render("withdrawal", {
          accountNumber: accountNumber,
        });
      }
    },
  );
});

app.post("/deposit", (req, res) => {
  if (!req.session.user) {
    return res.redirect("/");
  }

  const accountNumber = req.body.accountNumber;
  const depositAmount = req.body.depositAmount;
  const action = req.body.action;

  if (action == "cancel") {
    return res.redirect("/banking");
  }

  fs.readFile(
    path.join(__dirname, "accounts.json"),
    "utf8",
    function (err, data) {
      if (err) {
        console.error(err);
        return res.send("File Open Error");
      }

      const dataAccounts = JSON.parse(data);
      const account = dataAccounts[accountNumber];

      account.accountBalance =
        Number(account.accountBalance) + Number(depositAmount);

      fs.writeFile(
        path.join(__dirname, "accounts.json"),
        JSON.stringify(dataAccounts, null, 4),
        function (err) {
          if (err) {
            console.error(err);
            return res.send("File Write Error");
          }
          return res.redirect("/banking");
        },
      );
    },
  );
});

app.post("/openAccount", (req, res) => {
  if (!req.session.user) {
    return res.redirect("/");
  }

  const action = req.body.action;
  const accountType = req.body.accountType;

  if (action == "cancel") {
    return res.redirect("/banking");
  }

  if (action == "submit") {
    fs.readFile(
      path.join(__dirname, "accounts.json"),
      "utf8",
      function (err, data) {
        if (err) {
          console.error(err);
          return res.send("File Open Error");
        }

        const dataAccounts = JSON.parse(data);

        var nextLastID = Number(dataAccounts.lastID) + 1;
        var newAccountNum = String(nextLastID).padStart(7, "0");
        dataAccounts.lastID = newAccountNum;

        dataAccounts[newAccountNum] = {
          accountType: accountType,
          accountBalance: 0,
        };

        fs.writeFile(
          path.join(__dirname, "accounts.json"),
          JSON.stringify(dataAccounts, null, 4),
          function (err) {
            if (err) {
              console.error(err);
              return res.send("File Write Error");
            }

            const successMsg = `${accountType} Account #${newAccountNum} Created`;
            return res.render("banking", {
              inputUsername: req.session.user,
              successMsg: successMsg,
            });
          },
        );
      },
    );
  }
});

app.post("/withdrawal", (req, res) => {
  if (!req.session.user) {
    return res.redirect("/");
  }

  const accountNumber = req.body.accountNumber;
  const withdrawalAmount = req.body.withdrawalAmount;
  const action = req.body.action;

  if (action == "cancel") {
    return res.redirect("/banking");
  }

  fs.readFile(
    path.join(__dirname, "accounts.json"),
    "utf8",
    function (err, data) {
      if (err) {
        console.error(err);
        return res.send("File Open Error");
      }

      const dataAccounts = JSON.parse(data);
      const account = dataAccounts[accountNumber];

      if (Number(withdrawalAmount) > Number(account.accountBalance)) {
        return res.render("banking", {
          inputUsername: req.session.user,
          errorMsg: "Insufficient Funds",
        });
      }

      account.accountBalance =
        Number(account.accountBalance) - Number(withdrawalAmount);

      fs.writeFile(
        path.join(__dirname, "accounts.json"),
        JSON.stringify(dataAccounts, null, 4),
        function (err) {
          if (err) {
            console.error(err);
            return res.send("File Write Error");
          }
          return res.redirect("/banking");
        },
      );
    },
  );
});

app.all(/.*/, (req, res) => {
  res.status(404).send(`Catch-all route`);
});

const server = app.listen(HTTP_PORT, () => {
  console.log(`Listening on port ${HTTP_PORT}`);
});
