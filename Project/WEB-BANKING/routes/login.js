const express = require("express");
const router = express.Router();
const fs = require("fs");
const path = require("path");

router.get("/", (req, res) => {
  res.render("login");
});
router.get("/login", (req, res) => {
  res.render("login");
});
router.post("/login", (req, res) => {
  const inputUsername = req.body.Username;
  const inputPassword = req.body.Password;

  fs.readFile(path.join(__dirname, "../user.json"), "utf8", (err, data) => {
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

    return res.redirect("/banking");
  });
});

module.exports = router;
