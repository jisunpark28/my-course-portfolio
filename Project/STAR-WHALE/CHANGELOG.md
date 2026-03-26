# Changelog

All notable changes to the **Star Whale** project will be documented in this file.

## [2026-02-05] - Architecture Refinement
### Added
- **Whale State Machine**: Formalized the core interface logic including `Idle`, `Studying`, `Testing`, and `Result` states.
- **Star State Machine**: Implemented the gamification lifecycle (Empty, Filling, Twinkling, Gold, and Green states).
- **Incubation Logic**: Introduced a 10-day `Pending Activation` period for mastered (Green) words to automate Green Star formation.

### Changed
- **Terminology Standard**: Upgraded documentation language to professional IT standards (e.g., *State Synchronization*, *Metadata Streaming*).
- **Project Structure**: Organized design assets into a dedicated `docs/` directory.

### Fixed
- **Mermaid Syntax**: Corrected diagram rendering issues in `docs/state-transition.md`.