/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Game Controller
Purpose: Implements the core game loop, input processing, and win/loss conditions.
Filename: StarWhaleGame.cpp
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function implementation
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cctype>
#include "StarWhaleGame.h"
#include "StarlightHint.h"
#include "StardustHeal.h"

StarWhaleGame::StarWhaleGame()
    : m_player(nullptr), m_answer(nullptr), m_display(nullptr), m_isGameOver(false) {
}

StarWhaleGame::~StarWhaleGame() {
    cleanup();
}

void StarWhaleGame::cleanup() {
    delete m_player;
    delete[] m_answer;
    delete[] m_display;
    m_player = nullptr;
    m_answer = nullptr;
    m_display = nullptr;
    m_isGameOver = false;
}

bool StarWhaleGame::startNewGame(const char* filename, const char* playerName) {
    cleanup();

    if (!m_wordProvider.loadWords(filename)) return false;

    m_player = new PlayerProfile(playerName);
    m_player->addSkill(new StarlightHint()); // skillIndex 0
    m_player->addSkill(new StardustHeal());  // skillIndex 1

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

void StarWhaleGame::initializeDisplay() {
    const size_t len = std::strlen(m_answer);
    for (size_t i = 0; i < len; i++) {
        m_display[i] = '_';
    }
    m_display[len] = '\0';
}

bool StarWhaleGame::makeGuess(char letter) {
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

bool StarWhaleGame::revealOneHiddenLetter() {
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

void StarWhaleGame::useSkill(int skillIndex) {
    if (m_isGameOver || !m_player) return;

    ISkill* skill = m_player->getSkill(skillIndex);
    if (!skill) return;

    int beforeEnergy = m_player->getBridgeEnergy();
    skill->use(*m_player);

    if (skillIndex == 0 && m_player->getBridgeEnergy() < beforeEnergy) {
        revealOneHiddenLetter();
    }

    if (std::strcmp(m_answer, m_display) == 0) {
        m_player->addStarPiece(10);
        m_isGameOver = true;
    }

    if (!m_player->isAlive()) {
        m_isGameOver = true;
    }
}

const char* StarWhaleGame::getDisplayWord() const {
    return m_display ? m_display : "";
}

bool StarWhaleGame::isGameOver() const {
    return m_isGameOver;
}

const PlayerProfile* StarWhaleGame::getPlayer() const {
    return m_player;
}