# Progress log

이 파일은 **공부한 순서**를 남기는 포트폴리오입니다.  
코드만 보지 말고, 여기와 Git 커밋 메시지를 같이 보면 됩니다.

규칙:

- 한 단계 = 한 가지를 이해하거나 추가한다
- 단계가 끝나면 여기에 날짜와 배운 점을 적는다
- GitHub에는 그 단계만 커밋한다 (`git commit` 메시지 = 이 단계의 제목)

---

## Step 0 — 프로젝트 목적 (2026-08-13)

**한 일:** Learning Data Management System 저장소를 만들었다.

**왜:** 수업에서 배운 내용을 Markdown으로 모아 두고, HTML에서 CRUD로 관리하고 싶었다.

**배운 점:**

- CMS = Content Management System (웹 글 관리)
- 이 프로젝트는 학습 **데이터**를 다루니까 Data Management System이 더 가깝다
- CRUD = Create, Read, Update, Delete

**다음:** Markdown 노트 형식 정하기

---

## Step 1 — 노트 파일 구조 (2026-08-13)

**한 일:** `notes/` 폴더와 `_template.md`를 만들었다.

**왜:** 나중에 C#을 몰라도, 오늘은 학습 노트를 쌓을 수 있게.

**배운 점:**

- 한 파일 = 한 주제
- 과목은 폴더 이름 (`notes/OPS102/`)
- Linux vs Windows 비교는 파일명이 아니라 YAML의 `compare`에 넣는다
- 파일 이름에 `/` 를 쓰면 Windows에서 폴더로 깨진다

**다음:** 첫 학습 노트 작성

---

## Step 2 — 첫 노트, OPS102 files and directories (2026-08-13)

**한 일:** `notes/OPS102/files-and-directories.md`에 Linux / Windows 명령 비교를 정리했다.

**왜:** 수업 자료를 나중에 검색할 수 있는 형태로 남기기 위해.

**배운 점:**

- YAML front matter (`title`, `groups`, `topic`, `tags`)가 검색에 쓰인다
- `pwd` / `cd`, `ls` / `dir`, `cp` / `copy` 같이 같은 일을 하는 명령이 OS마다 다르다

**다음:** .NET SDK 설치 후 앱을 한 번 실행하기

---

## Roadmap (아직 안 함)

| Step | 할 일 | 이 단계에서 배우는 것 |
|------|--------|------------------------|
| 3 | .NET 8 SDK 설치, `dotnet run` | SDK vs Runtime, 웹 서버가 켜지는 것 |
| 4 | `wwwroot` HTML 화면 읽기 | 브라우저 CRUD가 버튼을 어떻게 쓰는지 |
| 5 | `Program.cs` 읽기 | C# 앱의 시작점 |
| 6 | `NotesController` GET | Read (조회) |
| 7 | POST import | Create (Markdown 저장) |
| 8 | PUT / DELETE | Update, Delete |
| 9 | MongoDB 연결 | VS Code에서 쓰던 DB와 앱이 붙는 방법 |
| 10 | 노트 하나 더 추가하고 import | 전체 흐름을 혼자 반복 |

새 단계를 끝낼 때마다 이 파일 위에 이어서 적는다. 아래 roadmap 표에서 해당 줄을 지우지 말고, 위에 로그를 쌓는다.
