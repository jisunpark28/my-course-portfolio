---
title: ASP.NET Core project structure (src, wwwroot, Controllers)
groups: [LearningDMS]
topic: aspnet
tags: [csharp, dotnet, wwwroot, convention, web-api]
---

ASP.NET Core는 폴더 이름을 정해 두고, 그 이름이면 설정 없이 동작하게 한다. 이 약속을 **convention over configuration**이라고 한다.

이 프로젝트 한 개를 부르는 말:

- ASP.NET Core Web API + static files
- HTML과 `/api`를 한 서버가 같이 주면 same-origin hosting

React처럼 프론트를 따로 띄우는 SPA는 아직 아니다. 지금은 **정적 HTML + Web API를 한 앱이 담당**한다.

## Folder layout

```
src/LearningCms.Api/
  Program.cs          ← C# (서버 시작점)
  Controllers/        ← /api/notes (JSON)
  wwwroot/
    index.html        ← 브라우저가 보는 화면
    app.js
    style.css
```

## What each part does

| Path | Role | Who runs it? |
|------|------|----------------|
| `src/` | 앱 소스 모음. 반드시 이 이름이어야 실행되는 것은 아님 | — |
| `LearningCms.Api/` | 실행되는 웹 프로젝트 하나 (`.csproj`) | .NET |
| `Program.cs` | 서버를 켜고, MongoDB 연결, `wwwroot` 공개, `/api` 연결 | .NET |
| `Controllers/` | `fetch('/api/notes')`를 받는 CRUD | .NET |
| `wwwroot/` | 웹 루트(Web root). 브라우저가 URL로 받는 파일 | 브라우저 |

`wwwroot`의 HTML/CSS/JS는 C#이 실행하지 않는다. **파일 그대로 전송**한다.

`src/index.html`에 두면 서버가 웹 주소로 안 준다. `UseStaticFiles()`가 여는 곳은 `wwwroot`뿐이다.

## Controllers and CRUD

| HTTP | CRUD | Example |
|------|------|---------|
| GET | Read | `/api/notes`, `/api/notes/{id}` |
| POST | Create | `/api/notes/import` |
| PUT | Update | `/api/notes/{id}` |
| DELETE | Delete | `/api/notes/{id}` |

응답은 HTML이 아니라 **JSON**.

## URLs from one server

- `http://localhost:5000` → `wwwroot/index.html`
- `http://localhost:5000/api/notes` → C# Controller

한 줄 요약: **동적 처리(C# API)와 정적 파일(HTML/CSS/JS)을 한 웹 앱에서 나눈다.** `wwwroot`는 정적 파일의 공식 폴더 이름이다.

## Google search terms

| Question | Search |
|----------|--------|
| `wwwroot`가 왜 있는지 | `ASP.NET Core wwwroot static files` |
| `src` 프로젝트 구조 | `ASP.NET Core project structure` |
| `Controllers` | `ASP.NET Core Web API controller` |
| `Program.cs` | `ASP.NET Core Program.cs WebApplication` |
| HTML이 자동으로 열리는 이유 | `ASP.NET Core UseStaticFiles UseDefaultFiles` |
| Content root vs wwwroot | `ASP.NET Core ContentRoot WebRoot` |

공식 문서 키워드: **Static files in ASP.NET Core**, **Web root (`wwwroot`)**.
