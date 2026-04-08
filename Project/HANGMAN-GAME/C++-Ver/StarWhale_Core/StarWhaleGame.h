/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Game Controller
Purpose: Declares the main game engine, state management, and rule validation.
Filename: StarWhaleGame.h
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function prototypes
-----------------------------------------------------------*/

#ifndef STARWHALE_GAME_H
#define STARWHALE_GAME_H

#include "FileWordProvider.h"
#include "PlayerProfile.h"

class StarWhaleGame {
    FileWordProvider m_wordProvider;
    PlayerProfile* m_player;
    char* m_answer;          // The correct word to guess
    char* m_display;         // The word shown to player (e.g., "S_N_C_")
    bool m_isGameOver;

    void cleanup();
    void initializeDisplay();
    bool revealOneHiddenLetter();

public:
    StarWhaleGame();
    ~StarWhaleGame();

    // Rule of Three
    StarWhaleGame(const StarWhaleGame&) = delete;
    StarWhaleGame& operator=(const StarWhaleGame&) = delete;

    // Starts a new session
    bool startNewGame(const char*, const char*);

    // Game Logic
    bool makeGuess(char);
    void useSkill(int);

    // Getters for UI
    const char* getDisplayWord() const;
    bool isGameOver() const;
    const PlayerProfile* getPlayer() const;
};

#endif