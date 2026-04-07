# C++ Hangman Game (Star Whale): Requirements Specification

## Architecture (OOP Design)
Below is the 5-tier architecture incorporating OOP principles and Test-Driven Development (TDD).

1. Data & State
   - WordData.h
   - PlayerProfile.h / .cpp
     - [Unit Test] PlayerProfile Testing -> test_PlayerProfile.cpp

2. Interfaces
   - IWordProvider.h
   - ISkill.h

3. Implementations
   - FileWordProvider.h / .cpp
     - [Unit Test] FileWordProvider Testing -> test_FileWordProvider.cpp
   - StarlightHint.h / .cpp
     - [Unit Test] StarlightHint Testing -> test_StarlightHint.cpp
   - StardustHeal.h / .cpp
     - [Unit Test] StardustHeal Testing -> test_StardustHeal.cpp

4. Engine & Display
   - StarWhaleGame.h / .cpp
     - [Integration Test] StarWhaleGame Testing -> test_StarWhaleGame.cpp
   - WhaleRenderer.h / .cpp
     - [Unit Test] WhaleRenderer Testing -> test_WhaleRenderer.cpp

5. Entry Point
   - main.cpp
     - [Acceptance Test] Main Testing -> test_Main.cpp

* Design Notes:
  - Use an `IWordProvider` interface (Pure Virtual Function) for easy Mock testing and dependency injection.
  - Track game status using internal state management within `StarWhaleGame`.
  - Hide internal variables in `PlayerProfile` to prevent direct outside access (Data Encapsulation).

## Security & Robustness
- Reject empty or extra-long inputs. Ignore case differences (case-insensitive).
- Strictly use parameterized queries for user inputs to prevent SQL Injection (if DB is integrated later).
- Use `try-catch` for all DB/File operations to handle exceptions (e.g., missing config files) and prevent game crashes.

## Business Requirement 
- Player gets exactly 6 bridge energies (lives).
- Load random words via `FileWordProvider` (implementing `IWordProvider`).
- If data saving/loading fails, log the error internally, load default fallback words, and keep playing (Fail-safe).
- (Optional/Future) Play "Review Mode" using the Top 5 recently failed words.

## Testing Strategy
- Achieve 100% unit test coverage for core data and logic (`FileWordProvider`, `PlayerProfile`, `ISkill` implementations).
- Perform Integration Testing (`test_StarWhaleGame.cpp`) to verify input rules, duplicate letters, HP deduction, and Win/Lose conditions.
- Test game recovery and exception handling when the word configuration file is missing or corrupted.

---

### Tech Stack
- **Language**: C++ (ISO/IEC 14882:2017)
- **Database**: Oracle Database (via OCCI) - *Reserved for future expansion*
- **Testing Framework**: Custom console-based C++ Test Drivers (Unit / Integration / Acceptance)