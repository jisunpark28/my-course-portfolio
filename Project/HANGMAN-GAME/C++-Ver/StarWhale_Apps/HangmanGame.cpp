/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Game Controller
Purpose: Implements the core game loop, input processing, and win/loss conditions.
Filename: HangmanGame.cpp
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
-----------------------------------------------------------*/

#include "HangmanGame.h"

#include <cctype>
#include <memory>

#include "HealSkill.h"
#include "HintSkill.h"

HangmanGame::HangmanGame() : m_isGameOver(false) {
}

bool HangmanGame::startNewGame(const std::string& wordFilePath, const std::string& playerName) {
    if (!m_wordProvider.loadWords(wordFilePath)) {
        m_player.reset();
        m_answerWord.clear();
        m_displayWord.clear();
        m_guessedLetters.clear();
        m_isGameOver = true;
        return false;
    }

    m_player = std::make_unique<HangmanPlayerProfile>(playerName);
    m_player->addSkill(std::make_unique<HintSkill>());
    m_player->addSkill(std::make_unique<HealSkill>());

    const HangmanWordData selected = m_wordProvider.getWord();
    m_answerWord = selected.word;
    m_displayWord = m_answerWord;
    for (char& ch : m_displayWord) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            ch = '_';
        }
    }

    m_guessedLetters.clear();
    m_isGameOver = false;
    return !m_answerWord.empty();
}

bool HangmanGame::makeGuess(char letter) {
    if (m_isGameOver || !m_player) {
        return false;
    }

    const char normalized = normalizeLetter(letter);
    if (!std::isalpha(static_cast<unsigned char>(normalized))) {
        return false;
    }

    if (m_guessedLetters.count(normalized) > 0) {
        return false;
    }
    m_guessedLetters.insert(normalized);

    bool found = false;
    for (std::size_t i = 0; i < m_answerWord.size(); ++i) {
        if (normalizeLetter(m_answerWord[i]) == normalized) {
            m_displayWord[i] = m_answerWord[i];
            found = true;
        }
    }

    if (!found) {
        m_player->decreaseEnergy();
        if (!m_player->isAlive()) {
            m_isGameOver = true;
        }
    }
    else if (isSolved()) {
        m_player->addStarPiece(10);
        m_isGameOver = true;
    }

    return found;
}

void HangmanGame::useHintSkill() {
    if (m_isGameOver || !m_player) {
        return;
    }

    HintSkill hintSkill;
    const int beforeEnergy = m_player->getBridgeEnergy();
    hintSkill.use(*m_player);

    if (m_player->getBridgeEnergy() < beforeEnergy) {
        revealOneHiddenLetter();
    }

    if (isSolved()) {
        m_player->addStarPiece(10);
        m_isGameOver = true;
    }
    else if (!m_player->isAlive()) {
        m_isGameOver = true;
    }
}

void HangmanGame::useHealSkill() {
    if (m_isGameOver || !m_player) {
        return;
    }

    HealSkill healSkill;
    healSkill.use(*m_player);
}

bool HangmanGame::isGameOver() const {
    return m_isGameOver;
}

bool HangmanGame::isSolved() const {
    return !m_answerWord.empty() && m_answerWord == m_displayWord;
}

const std::string& HangmanGame::getDisplayWord() const {
    return m_displayWord;
}

const HangmanPlayerProfile* HangmanGame::getPlayer() const {
    return m_player.get();
}

std::string HangmanGame::getHintText() const {
    if (m_answerWord.empty()) {
        return "No hint available.";
    }
    return m_wordProvider.getHintForWord(m_answerWord);
}

bool HangmanGame::revealOneHiddenLetter() {
    for (std::size_t i = 0; i < m_displayWord.size(); ++i) {
        if (m_displayWord[i] == '_') {
            m_displayWord[i] = m_answerWord[i];
            return true;
        }
    }
    return false;
}

char HangmanGame::normalizeLetter(char letter) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(letter)));
}