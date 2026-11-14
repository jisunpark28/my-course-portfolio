/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Game Controller
Purpose: Implements the core game loop, input processing, and win/loss conditions.
Filename: HangmanGame.cpp
Version 0.5
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function implementation
2026/11/13  Inject IWordProvider via constructor (loadWords -> load)
2026/11/13  Use polymorphic revealsLetter(); remove skillIndex check
2026/11/13  Rename classes, files, and screen text to Word Hint Hangman
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cctype>
#include "HangmanGame.h"
#include "LetterHint.h"
#include "EnergyHeal.h"

HangmanGame::HangmanGame(IWordProvider& provider)
    : m_wordProvider(provider), m_player(nullptr), m_answer(nullptr), m_display(nullptr), m_isGameOver(false) {
}

HangmanGame::~HangmanGame() {
    cleanup();
}

void HangmanGame::cleanup() {
    delete m_player;
    delete[] m_answer;
    delete[] m_display;
    m_player = nullptr;
    m_answer = nullptr;
    m_display = nullptr;
    m_isGameOver = false;
}

bool HangmanGame::startNewGame(const char* filename, const char* playerName) {
    cleanup();

    if (!m_wordProvider.load(filename)) return false;

    m_player = new PlayerProfile(playerName);
    m_player->addSkill(new LetterHint()); // skillIndex 0
    m_player->addSkill(new EnergyHeal());  // skillIndex 1

    const char* picked = m_wordProvider.getRandomWord();
    if (!picked || picked[0] == '\0') {
        cleanup();
        return false;
    }

    m_answer = new char[std::strlen(picked) + 1];
    std::strcpy(m_answer, picked);

    m_display = new char[std::strlen(m_answer) + 1];
    initializeDisplay();

    m_isGameOver = false;
    return true;
}

void HangmanGame::initializeDisplay() {
    const size_t len = std::strlen(m_answer);
    for (size_t i = 0; i < len; i++) {
        m_display[i] = '_';
    }
    m_display[len] = '\0';
}

bool HangmanGame::makeGuess(char letter) {
    if (m_isGameOver || !m_player || !m_answer || !m_display) return false;

    const char normalized = static_cast<char>(std::toupper(static_cast<unsigned char>(letter)));
    bool found = false;
    const size_t len = std::strlen(m_answer);

    for (size_t i = 0; i < len; i++) {
        if (std::toupper(static_cast<unsigned char>(m_answer[i])) == normalized) {
            m_display[i] = m_answer[i];
            found = true;
        }
    }

    if (!found) {
        m_player->decreaseEnergy();
        if (!m_player->isAlive()) {
            m_isGameOver = true;
        }
    }
    else if (std::strcmp(m_answer, m_display) == 0) {
        m_player->addStarPiece(10); // Victory bonus
        m_isGameOver = true;
    }

    return found;
}

bool HangmanGame::revealOneHiddenLetter() {
    if (!m_answer || !m_display) return false;

    const size_t len = std::strlen(m_answer);
    for (size_t i = 0; i < len; ++i) {
        if (m_display[i] == '_') {
            m_display[i] = m_answer[i];
            return true;
        }
    }
    return false;
}

bool HangmanGame::useSkill(int skillIndex) {
    if (m_isGameOver || !m_player) return false;
    ISkill* skill = m_player->getSkill(skillIndex);
    if (!skill) return false;
    if (!skill->use(*m_player)) return false;      // Not applied
    if (skill->revealsLetter()) revealOneHiddenLetter();
    if (std::strcmp(m_answer, m_display) == 0) {
        m_player->addStarPiece(10);
        m_isGameOver = true;
    }
    if (!m_player->isAlive()) {
        m_isGameOver = true;
    }
    return true;
}

const char* HangmanGame::getDisplayWord() const {
    return m_display ? m_display : "";
}

bool HangmanGame::isGameOver() const {
    return m_isGameOver;
}

const PlayerProfile* HangmanGame::getPlayer() const {
    return m_player;
}