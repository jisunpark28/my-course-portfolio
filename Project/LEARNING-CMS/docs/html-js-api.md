---
title: HTML ↔ JS ↔ API contract
groups: [LearningDMS]
topic: contract
tags: [html, javascript, api, ids]
---

Start from the wireframe, then name the same value in each layer.

```
Picture  →  HTML  →  JS  →  API  →  DB
```

## Fields (picture → layers)

| Picture | HTML | JS | API | DB |
|---------|------|-----|-----|-----|
| search words... | `#search-input` | `query` | `GET /api/notes?q=` | text search |
| Title | `#edit-topic` | `title` | YAML `title` / JSON `topic` | `Topic` |
| #group | `#edit-groups` | `groups` | `groups` | `Groups` |
| #topic | `#edit-note-topic` | `noteTopic` | YAML `topic` | in Markdown (no column yet) |
| #tags | `#edit-tags` | `tags` | `tags` | `Tags` |
| contents | `#edit-markdown` | `body` | `rawMarkdown` | `RawMarkdown` |
| (not on picture) | — | `selectedId` | `/api/notes/{id}` | `_id` |
| list row title | `.result-topic` | `title` | `topic` | `Topic` |
| list row group | `.result-group` | `groups` | `groups` | `Groups` |
| list row preview | `.result-preview` | preview of `body` | `rawMarkdown` | `RawMarkdown` |

Same row = same data. HTML `id` is the box; API/DB never see `#edit-topic`.

## Actions (picture → HTTP)

| Picture | HTML | JS | API |
|---------|------|-----|-----|
| Search | `#search-form` | read `query`; fill `#results` | `GET /api/notes` or `?q=` |
| + (Create) | `#create-btn` | clear Title, group, topic, tags, contents | later `POST /api/notes/import` |
| Update | `#edit-btn` | read those fields; send with `selectedId` | `PUT /api/notes/{id}` |
| Delete | `#delete-btn` | send `selectedId` | `DELETE /api/notes/{id}` |
| list row click | `.result-item` | set `selectedId`; write fields on the right | `GET /api/notes/{id}` |

## List

| Picture | HTML | JS |
|---------|------|-----|
| left sidebar | `#results` | clone `#result-template` into this `<ul>` |
| default | grouped list | no `query` → all notes, grouped by `groups` |
| after search | filtered list | `query` → matches only |

`selectedId` lives in JS only. Title / group / topic / tags / contents are both **read** (Update) and **write** (row click).
