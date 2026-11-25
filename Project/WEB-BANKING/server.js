const HTTP_PORT = process.env.PORT || 3000;

const express = require("express");
const exphbs = require("express-handlebars");
const path = require("path");
const fs = require("fs");
const app = express();

app.engine(
  ".hbs",
  exphbs.engine({
    extname: ".hbs",
    defaultLayout: false,
    layoutsDir: path.join(__dirname, "/views"),
  }),
);

app.set("view engine", ".hbs");
app.set("views", path.join(__dirname, "/views"));

app.use("/", express.static(path.join(__dirname, "/public")));
app.use("/images", express.static(path.join(__dirname, "/images")));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

app.get("/", (req, res) => {
  res.render("login");
});

app.get("/login", (req, res) => {
  res.render("login");
});

app.get("/banking", (req, res) => {
  res.redirect("/");
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

    res.render("banking", { inputUsername: inputUsername });
  });
});

app.post("/banking", (req, res) => {
  res.send("Not implemented yet");
});

app.all(/.*/, (req, res) => {
  res.status(404).send(`Catch-all route`);
});

const server = app.listen(HTTP_PORT, () => {
  console.log(`Listening on port ${HTTP_PORT}`);
});
