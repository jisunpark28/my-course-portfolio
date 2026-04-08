/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Game Controller
Purpose: Declares the main game engine, state management, and rule validation.
Filename: HangmanGame.h
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
-----------------------------------------------------------*/

#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H

#include <memory>
#include <set>
#include <string>

#include "FileHangmanWordProvider.h"
#include "HangmanPlayerProfile.h"

class HangmanGame {
private:
    FileHangmanWordProvider m_wordProvider;
    std::unique_ptr<HangmanPlayerProfile> m_player;
    std::string m_answerWord;
    std::string m_displayWord;
    std::set<char> m_guessedLetters;
    bool m_isGameOver;

    bool revealOneHiddenLetter();
    static char normalizeLetter(char letter);

public:
    HangmanGame();

    bool startNewGame(const std::string& wordFilePath, const std::string& playerName);
    bool makeGuess(char letter);

    void useHintSkill();
    void useHealSkill();

    bool isGameOver() const;
    bool isSolved() const;
    const std::string& getDisplayWord() const;
    const HangmanPlayerProfile* getPlayer() const;
    std::string getHintText() const;
};

#endif