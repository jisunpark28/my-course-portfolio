/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Renderer
Purpose: Implements the drawing logic for the bridge, Star Whale, and game screens.
Filename: HangmanRenderer.cpp
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
-----------------------------------------------------------*/

#include "HangmanRenderer.h"

#include <iostream>

namespace {
const char* kReset = "\x1b[0m";
const char* kCyan = "\x1b[36m";

void printMaybeColored(const std::string& text, bool useColor) {
    if (useColor) {
        std::cout << kCyan << text << kReset;
    }
    else {
        std::cout << text;
    }
}
}

HangmanRenderer::HangmanRenderer() : m_currentStage(0), m_useColor(false) {
}

void HangmanRenderer::setStage(int stage) {
    if (stage < 0) {
        m_currentStage = 0;
    }
    else if (stage > 6) {
        m_currentStage = 6;
    }
    else {
        m_currentStage = stage;
    }
}

int HangmanRenderer::getStage() const {
    return m_currentStage;
}

void HangmanRenderer::setUseColor(bool enabled) {
    m_useColor = enabled;
}

bool HangmanRenderer::isColorEnabled() const {
    return m_useColor;
}

void HangmanRenderer::renderTitle() const {
    printMaybeColored("\n=== Star Whale Hangman ===\n", m_useColor);
}

void HangmanRenderer::renderStage() const {
    static const char* stages[] = {
        " +---+\n |   |\n     |\n     |\n     |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n     |\n     |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n |   |\n     |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n/|   |\n     |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n/|\\  |\n     |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n/|\\  |\n/    |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n/|\\  |\n/ \\  |\n     |\n=======\n"
    };

    printMaybeColored(stages[m_currentStage], m_useColor);
}

void HangmanRenderer::renderGameState(
    const std::string& playerName,
    int bridgeEnergy,
    int starPieces,
    const std::string& displayWord) const {
    renderTitle();
    renderStage();
    std::cout << "Player: " << playerName
              << " | Energy: " << bridgeEnergy
              << " | Score: " << starPieces << '\n';
    std::cout << "Word: " << displayWord << '\n';
}