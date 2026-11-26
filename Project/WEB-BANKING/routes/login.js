// initialize express sub-router
const express = require("express");
const router = express.Router();
// file system modules
const fs = require("fs");
const path = require("path");

// rener login page ("/" and "/login")
router.get("/", (req, res) => {
  res.render("login");
});
router.get("/login", (req, res) => {
  res.render("login");
});

// authenticate user credentials against user.json
router.post("/login", (req, res) => {
  const inputUsername = req.body.Username;
  const inputPassword = req.body.Password;

  // read user credentials file (asynchronous)
  fs.readFile(path.join(__dirname, "../user.json"), "utf8", (err, data) => {
    if (err) {
      console.error(err);
      return res.send("File Open Error");
    }

    // parsing json(data) to object(dataUsers)
    const dataUsers = JSON.parse(data);

    // verify username exists
    if (dataUsers[inputUsername] == undefined) {
      return res.render("login", {
        errorMsg: "Not a registered username",
        username: inputUsername,
        password: inputPassword,
      });
    }
    // verify password mathces
    if (dataUsers[inputUsername] !== inputPassword) {
      return res.render("login", {
        errorMsg: "Invalid password",
        username: inputUsername,
        password: inputPassword,
      });
    }

    // store authenticated username in session
    req.session.user = inputUsername;
    return res.redirect("/banking");
  });
});

module.exports = router;
