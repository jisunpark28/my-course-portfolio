# C++ Hangman Game: Requirements Specification

## Architecture (OOP Design)
- Use a `WordLoader` interface (Pure Virtual Function) for easy Mock testing.
- Track game status using `enum { ONGOING, WIN, LOSE }`.
- Hide internal variables to prevent direct outside access (Data Privacy).

## Security & Robustness
- Reject empty or extra-long inputs. Ignore case differences (case-insensitive).
- Strictly use parameterized queries for user inputs to prevent SQL Injection.
- Use `try-catch` for all DB operations to handle `SQLException` and stop game crashes.

## Business Requirement 
- Player gets exactly 6 lives.
- Load random words via `WordLoader`.
- If DB saving fails, just log the error internally and keep playing (Fail-safe).
- Play "Review Mode" using the Top 5 recently failed words.

## Testing Strategy
- Achieve 100% unit test coverage for core logic (`WordManager`, `Player`).
- Test game recovery when DB connection is lost.
- Verify input rules, duplicate letters, and Win/Lose conditions.

---

### Tech Stack
- **Language**: C++ (ISO/IEC 14882:2017)
- **Database**: Oracle Database (via OCCI)
- **Testing Framework**: Microsoft Native Unit Test Framework (Visual Studio)