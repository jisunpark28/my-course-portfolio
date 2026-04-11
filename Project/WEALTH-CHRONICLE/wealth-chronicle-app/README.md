# Wealth Chronicle Calendar (English App)

This app helps parents track a child's financial mindset in a **calendar-based log format**, with:

- Personal calendar log storage
- Photo upload + rich record fields + tags
- One-click upload to a connected Instagram account (via Instagram Graph API)
- English UI and English log/caption format

---

## Features

1. **Calendar-Centered Logging**
   - Click any date in the monthly calendar.
   - Add one or multiple entries for the selected day.
   - Edit/Delete each saved record.

2. **Record Structure Matching Requested Format**
   - Chronicle title / volume / entry number
   - Entry title
   - Photo + photo description
   - Date
   - Activity
   - Fact/Status
   - Process
   - Child reaction and child quote
   - Analyst comment
   - Tags

3. **One-Button Instagram Upload**
   - Each saved entry has an **Upload to Instagram** button.
   - Backend automatically builds caption text from the record.
   - Publishes to the connected Instagram Professional account.

---

## Tech Stack

- Frontend: React + Vite
- Backend: Node.js + Express
- Upload: Multer
- Storage: Local JSON file (`data/logs.json`) + uploaded images (`uploads/`)

---

## Project Structure

```text
wealth-chronicle-app/
├─ src/                 # React UI
├─ server/index.js      # Express API + Instagram upload integration
├─ data/logs.json       # Personal calendar log storage
├─ uploads/             # Uploaded photos
├─ .env.example         # Environment variable template
└─ vite.config.js       # Frontend proxy (/api, /uploads)
```

---

## Setup

### 1) Install dependencies

```bash
npm install
```

### 2) Configure environment variables

Copy `.env.example` to `.env` and set values:

```bash
cp .env.example .env
```

Required for Instagram publishing:

- `IG_USER_ID`
- `IG_ACCESS_TOKEN`

Optional:

- `PUBLIC_BASE_URL` (must be publicly reachable if Instagram needs to fetch local uploaded images)
- `CLIENT_ORIGIN`
- `PORT`

### 3) Run app (frontend + backend)

```bash
npm run dev
```

- Frontend: `http://localhost:5173`
- API: `http://localhost:4000`

---

## Instagram Integration Notes

Instagram direct publishing uses the Instagram Graph API (`/{ig-user-id}/media` then `/media_publish`).

To work in production:

1. Use an **Instagram Professional account** linked to a Facebook Page.
2. Use a Facebook app/access token with required permissions:
   - `instagram_basic`
   - `instagram_content_publish`
   - `pages_read_engagement`
   - `pages_show_list`
3. Ensure the image URL sent to Instagram is publicly accessible.

If your uploaded local image URL is not public, provide a public image URL in:
**"Public image URL for Instagram (optional override)"**.

---

## Example Output Style

The preview card and Instagram caption follow this style:

```text
[Goeun's Wealth Chronicle: Vol. 1]
1st record: The beginning of financial independence
Photo: A first snapshot of four piggy banks (S, P, G, I)
Date: March 8, 2026

Log Details:
Activity: ...
Child reaction: ...
Analyst comment: ...
#save #spend #give #invest
```
