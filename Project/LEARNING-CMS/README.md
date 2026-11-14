# Learning Data Management System

Markdown 학습 노트를 **생성 · 조회 · 수정 · 삭제(CRUD)** 하는 개인 지식 정리 앱입니다.

GitHub에서 이 저장소를 보면 **커밋 기록 + [PROGRESS.md](PROGRESS.md)** 가 공부 순서입니다.

C# / .NET을 처음 배운다는 기준으로 폴더를 나눴습니다. 각 파일이 무슨 역할인지만 알면 코드를 읽기 수월합니다.

## 포트폴리오로 남기는 방법

1. 한 가지만 한다 (노트 하나, 또는 코드 한 부분).
2. `PROGRESS.md`에 Step을 적는다 (한 일 / 왜 / 배운 점).
3. 그 파일들만 커밋한다. 메시지 예: `Add OPS102 files-and-directories note`

커밋 하나가 포트폴리오의 한 페이지다. 여러 단계를 한 커밋에 넣지 않는다.

## 기술이 하는 일

| 이름 | 역할 | 이 프로젝트에서 |
|------|------|-----------------|
| **HTML / JS** | 화면 | `wwwroot` — 버튼, 검색창, 에디터 |
| **C#** | 프로그램 코드 | Controller, Model, Service |
| **.NET** | C#을 실행하는 플랫폼 | `dotnet run`으로 웹 서버를 띄움 |
| **MongoDB** | 데이터 저장소 | 노트가 collection에 쌓임 |
| **Markdown** | 네가 직접 쓰는 원본 | `notes/` 폴더 |

흐름:

```
브라우저 HTML  →  C# API (.NET)  →  MongoDB
     ↑                                    ↑
  wwwroot                    notes/*.md 를 import 해서 저장
```

C++은 여기 쓰지 않습니다. 웹 CRUD 서버를 C#으로 만든 구조입니다.

## 폴더 구조

```
LEARNING-CMS/
├── notes/                          ← 학습 노트는 모두 여기 (과목 폴더 없음)
│   ├── _template.md
│   ├── files-and-directories.md
│   └── aspnet-project-structure.md
├── samples/                        ← 예전 예시 (C++ copy vs move)
├── docker-compose.yml              ← 로컬 MongoDB (Docker 쓸 때)
└── src/LearningCms.Api/
    ├── Program.cs                  ← 앱 시작점. 여기서 서버가 켜짐
    ├── Controllers/NotesController.cs  ← CRUD URL (Create/Read/Update/Delete)
    ├── Models/                     ← 노트 데이터의 모양
    ├── Services/                   ← Markdown 파싱, 검색, 저장 로직
    ├── Data/                       ← MongoDB 연결
    └── wwwroot/                    ← HTML CRUD 화면
```

## 노트 만드는 방법

1. `notes/_template.md`를 복사한다. 예: `notes/permissions.md`
2. 파일 맨 위 YAML에서 `title`, `groups`, `topic`, `tags`를 고친다. `groups`는 과목(OPS102)과 프로젝트(LearningDMS)를 한 목록에 넣는다.
3. 앱을 켠 뒤 HTML에서 `.md 파일` 버튼으로 import 한다.

파일 이름은 서로 겹치지 않게 한다. `/` 나 `()` 는 쓰지 마세요.

## 실행 (처음 한 번 설치)

1. [.NET 8 SDK](https://dotnet.microsoft.com/download/dotnet/8.0)
2. MongoDB — VS Code에서 쓰던 연결이 `localhost:27017`이면 그대로 사용.
   Docker를 쓰면 프로젝트 폴더에서 `docker compose up -d`
3. 서버 실행:

```powershell
cd src\LearningCms.Api
dotnet restore
dotnet run
```

- 화면: http://localhost:5000
- API 목록: http://localhost:5000/swagger

## CRUD가 코드에서 어디인지

| CRUD | 브라우저 | C# (`NotesController`) | HTTP |
|------|----------|------------------------|------|
| Create | Markdown 저장 / 파일 import | `ImportMarkdown` | POST |
| Read | 검색, 목록, 상세 | `Search`, `GetById` | GET |
| Update | 수정 저장 | `Update` | PUT |
| Delete | 삭제 | `Delete` | DELETE |
