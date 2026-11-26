# web-banking

Server-side rendered banking app built with **Node.js, Express, Handlebars, express-session, and MongoDB Atlas**. Built in three stages, from JSON-file login to session-based transactions and cloud persistence.

**Live Demo:** https://my-course-portfolio-z7cp.vercel.app/  
**Demo Login:** `demo1@example.com / Demo1234` (or `demo2@example.com / Demo5678`)

## Architecture
![Architecture](./docs/images/archtecture%20map.png)

## Features
- **Auth & session guard:** credential validation, session-protected routes backed by MongoDB (connect-mongo), and hover-revealed logout on the banking view
- **Accounts:** auto-generated 7-digit account numbers, with one Chequing and one Savings account allowed per client
- **Transactions:** server-side deposits and withdrawals rounded to two decimal places, with Insufficient Funds blocking overdrafts
- **Modular routes:** login routes separated into an Express Router module (routes/login.js)

## Roadmap
| Version | Stage | Highlights |
| :--- | :--- | :--- |
| v1.0 | Auth & SSR | Login and banking views, user.json credential checks with error messages, hover-revealed logout |
| v2.0 | Sessions | Cookies and sessions, shared header partial, accounts.json with lastID, and balance, deposit, withdraw, and open-account flows |
| v3.0 | Cloud DB | MongoDB Atlas (clients and accounts collections), MongoDB session store (connect-mongo), user-scoped dropdowns, one account per type, Express Router, and Vercel deploy |

## Tech Stack
Node.js · Express · Express-Handlebars · express-session · connect-mongo · dotenv · randomstring · MongoDB Atlas · Vercel

## Run Locally
```bash
git clone https://github.com/jisunpark28/my-course-portfolio.git
cd my-course-portfolio/Project/WEB-BANKING
npm install
# Create .env with MONGODB_URI (pointing to a `webbank_demo` DB with `clients` and `accounts` collections) and SESSION_SECRET
npm start   # http://localhost:3000
