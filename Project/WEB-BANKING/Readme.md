# web-banking

Server-side rendered banking app built with **Node.js, Express, Handlebars, express-session, and MongoDB Atlas**. It was built in three stages, from JSON-file login to session-based transactions and cloud persistence.

## Features
- **Auth & session guard:** credential validation, session-protected routes, and logout from every view
- **Accounts:** auto-generated account numbers, with one Chequing and one Savings account allowed per client
- **Transactions:** server-side deposits and withdrawals, with `Insufficient Funds` blocking overdrafts
- **Modular routes:** banking functions separated into Express Router modules

## Roadmap
| Version | Stage | Highlights |
| :--- | :--- | :--- |
| v1.0 | Auth & SSR | Login and banking views, `user.json` credential checks with error messages, hover-revealed logout |
| v2.0 | Sessions | Cookies and sessions, shared header partial, `accounts.json` with `lastID`, and balance, deposit, withdraw, and open-account flows |
| v3.0 | Cloud DB | MongoDB Atlas (Clients and Accounts collections), user-scoped dropdowns, one account per type, Express Router, and Vercel deploy |

## Tech Stack
Node.js · Express · Express-Handlebars · express-session · randomstring · MongoDB Atlas · Vercel

## Run Locally
```bash
git clone https://github.com/jisunpark28/my-course-portfolio.git
cd my-course-portfolio/Project/WEB-BANKING
npm install
# create .env with MONGODB_URI and SESSION_SECRET
npm start   # http://localhost:3000
```
