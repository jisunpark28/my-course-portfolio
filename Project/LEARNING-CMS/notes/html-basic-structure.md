---
title: HTML basic structure
groups: [LearningDMS]
topic: html
tags: [html, html5, tags, wwwroot]
---

HTML = HyperText Markup Language. Text plus structure.

| Term | Meaning | Example |
|------|---------|---------|
| content | plain text | `Hello` |
| tag | name in `<>` | `<p>`, `<img>` |
| element | open + content + close | `<h1>Chapter 1</h1>` |
| attribute | extra info on a tag | `id="error"`, `hidden` |
| entity | special chars | `&lt;` `<` · `&amp;` `&` · `&nbsp;` space |

```html
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8" />
    <title>My Web Page</title>
  </head>
  <body>
    <!-- comment -->
    <h1>Hello World!</h1>
  </body>
</html>
```

| Line | Role |
|------|------|
| `<!DOCTYPE html>` | HTML5 |
| `<html>` | root |
| `<head>` | metadata (not page text) |
| `<meta charset="utf-8">` | encoding |
| `<title>` | browser tab |
| `<body>` | visible content |
| `<!-- ... -->` | comment |
| `<h1>` … `<h6>` | headings |

This app: `wwwroot/index.html` is that document. Browser URL `/` serves it.

## Metadata

```html
<link rel="stylesheet" href="/style.css" />
<meta charset="utf-8" />
<title>Learning Data Management System</title>
```

## Layout

```html
<html>
  <head>...</head>
  <body>
    <header>...</header>
    <nav>...</nav>
    <main>...</main>
    <footer>...</footer>
  </body>
</html>
```

## Text

```html
<div>...</div>
<p>paragraph</p>
<ul>
  <li>bullet</li>
</ul>
<ol>
  <li>numbered</li>
</ol>
<blockquote>quote</blockquote>
```

## Inline

```html
<a href="/">link</a>
<code>mkdir</code>
<em>emphasis</em>
<span>style hook</span>
```

## Media / script

```html
<img src="photo.png" alt="desc" />
<script src="/app.js"></script>
```

`index.html` = structure · `style.css` via `<link>` · `app.js` via `<script>`.
