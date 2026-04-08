/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Renderer
Purpose: Implements the drawing logic for the bridge, Star Whale, and game screens.
Filename: WhaleRenderer.cpp
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add StarWhaleGame Module Unit Test Cases
-----------------------------------------------------------*/

#include <iostream>
#include "WhaleRenderer.h"

WhaleRenderer::WhaleRenderer() : m_currentStage(0) {}

void WhaleRenderer::setStage(int stage) {
    // Stage 7 and 8 are special victory animation stages
    if (stage >= 0 && stage <= 8) {
        m_currentStage = stage;
    }
}

int WhaleRenderer::getStage() const {
    return m_currentStage;
}

void WhaleRenderer::render() const {
    std::cout << "\n[ Whale Status ]" << std::endl;

    // Render based on the current stage (0-6 for failures, 7-8 for victory)
    switch (m_currentStage) {
    case 0: // Initial State (Empty gallows)
        std::cout << "        +---+" << std::endl;
        std::cout << "        |   |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "      =========" << std::endl;
        break;
    case 1: // Head
        std::cout << "        +---+" << std::endl;
        std::cout << "        |   |" << std::endl;
        std::cout << "        o   |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "      =========" << std::endl;
        break;
    case 2: // Body
        std::cout << "        +---+" << std::endl;
        std::cout << "        |   |" << std::endl;
        std::cout << "        o   |" << std::endl;
        std::cout << "        |   |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "      =========" << std::endl;
        break;
    case 3: // One Arm
        std::cout << "        +---+" << std::endl;
        std::cout << "        |   |" << std::endl;
        std::cout << "        o   |" << std::endl;
        std::cout << "       /|   |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "      =========" << std::endl;
        break;
    case 4: // Both Arms
        std::cout << "        +---+" << std::endl;
        std::cout << "        |   |" << std::endl;
        std::cout << "        o   |" << std::endl;
        std::cout << "       /|\\  |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "      =========" << std::endl;
        break;
    case 5: // One Leg
        std::cout << "        +---+" << std::endl;
        std::cout << "        |   |" << std::endl;
        std::cout << "        o   |" << std::endl;
        std::cout << "       /|\\  |" << std::endl;
        std::cout << "       /    |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "      =========" << std::endl;
        break;
    case 6: // Final Stage (Game Over)
        std::cout << "        +---+" << std::endl;
        std::cout << "        |   |" << std::endl;
        std::cout << "        o   |" << std::endl;
        std::cout << "       /|\\  |" << std::endl;
        std::cout << "       / \\  |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "      =========" << std::endl;
        std::cout << "!!! GAME OVER !!!" << std::endl;
        break;
    case 7: // Victory Pose 1 (Left arm up)
        std::cout << "        +---+" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "       \\ o  |" << std::endl;
        std::cout << "        |\\  |" << std::endl;
        std::cout << "       / \\  |" << std::endl;
        std::cout << "      =========" << std::endl;
        std::cout << "   YOU WON! (1/2)" << std::endl;
        break;
    case 8: // Victory Pose 2 (Right arm up - Dancing)
        std::cout << "        +---+" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "            |" << std::endl;
        std::cout << "        o / |" << std::endl;
        std::cout << "       /|   |" << std::endl;
        std::cout << "       / \\  |" << std::endl;
        std::cout << "      =========" << std::endl;
        std::cout << "   YOU WON! (2/2)" << std::endl;
        break;
    }
    std::cout << "----------------" << std::endl;
}