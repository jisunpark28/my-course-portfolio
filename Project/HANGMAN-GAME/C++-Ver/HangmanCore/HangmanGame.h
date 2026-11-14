/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Game Controller
Purpose: Declares the main game engine, state management, and rule validation.
Filename: HangmanGame.h
Version 0.4
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function prototypes
2026/11/13  Inject IWordProvider via constructor (dependency injection); useSkill() returns bool
2026/11/13  Rename classes, files, and screen text to Word Hint Hangman
-----------------------------------------------------------*/

#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H

#include "FileWordProvider.h"
#include "PlayerProfile.h"

class HangmanGame {
    IWordProvider& m_wordProvider;   // Injected; game does not own it
    PlayerProfile* m_player;
    char* m_answer;          // The correct word to guess
    char* m_display;         // The word shown to player (e.g., "S_N_C_")
    bool m_isGameOver;

    void cleanup();
    void initializeDisplay();
    bool revealOneHiddenLetter();

public:
    explicit HangmanGame(IWordProvider& provider);
    ~HangmanGame();

    // Rule of Three
    HangmanGame(const HangmanGame&) = delete;
    HangmanGame& operator=(const HangmanGame&) = delete;

    // Starts a new session
    bool startNewGame(const char*, const char*);

    // Game Logic
    bool makeGuess(char);
    bool useSkill(int);

    // Getters for UI
    const char* getDisplayWord() const;
    bool isGameOver() const;
    const PlayerProfile* getPlayer() const;
};

#endif