# web-banking

Server-side rendered banking app built with **Node.js, Express, Handlebars, express-session, and MongoDB Atlas**. It was built in three stages, from JSON-file login to session-based transactions and cloud persistence.

## Features
- **Auth & session guard:** credential validation, session-protected routes, and logout from every view
- **Accounts:** sequential account numbers, with one Chequing and one Savings account allowed per client
- **Transactions:** server-side deposits and withdrawals, with `Insufficient Funds` blocking overdrafts
- **Modular routes:** business logic split into dedicated Express routers

## Roadmap
| Version | Stage | Highlights |
| :--- | :--- | :--- |
| v1.0 | Auth & SSR | Login and banking views, plus JSON-based credential checks |
| v2.0 | Sessions | Cookies and sessions, a shared header partial, and balance, deposit, and withdraw flows |
| v3.0 | Cloud DB | MongoDB Atlas, user-scoped dropdowns, modular routers, and Vercel deploy |

## Tech Stack
Node.js · Express · Express-Handlebars · express-session · MongoDB Atlas · Vercel

## Run Locally
```bash
git clone https://github.com/jisunpark28/my-course-portfolio.git
cd my-course-portfolio/Project/WEB-BANKING
npm install
# create .env with MONGODB_URI and SESSION_SECRET (v3.0)
npm start   # http://localhost:3000
```
