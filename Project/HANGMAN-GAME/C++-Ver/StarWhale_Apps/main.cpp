/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Entry Point
Purpose: Initializes dependencies and starts the Star Whale application.
Filename: main.cpp
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/09  Implement the main code
2026/04/10  Add hint feature
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "StarWhaleGame.h"
#include "WhaleRenderer.h"
#include "StarlightHint.h"
#include "StardustHeal.h"
#include "PlayerProfile.h"

int main() {
    StarWhaleGame game;
    WhaleRenderer renderer;
    char playerName[50];
    char guess;

    std::cout << "--- Welcome to Star Whale Hangman ---" << std::endl;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    // Start game with a words file
    if (!game.startNewGame("words.txt", playerName)) {
        std::cout << "Failed to load words.txt. Please check the file." << std::endl;
        return 1;
    }

    // Main Game Loop
    while (!game.isGameOver()) {
        renderer.setStage(6 - game.getPlayer()->getBridgeEnergy());
        renderer.render();

        std::cout << "Player: " << game.getPlayer()->getName()
            << " | Energy: " << game.getPlayer()->getBridgeEnergy()
            << " | Score: " << game.getPlayer()->getStarPieces() << std::endl;
        std::cout << "Word: " << game.getDisplayWord() << std::endl;
        std::cout << "Enter a letter to guess (or 1 for Hint, 2 for Heal): ";
        std::cin >> guess;

        if (guess == '1') {
            game.useSkill(0); // Starlight Hint
        }
        else if (guess == '2') {
            game.useSkill(1); // Stardust Heal
        }
        else {
            if (game.makeGuess(guess)) {
                std::cout << ">> Correct!" << std::endl;
            }
            else {
                std::cout << ">> Wrong guess..." << std::endl;
            }
        }
    }

    // Final Result
    renderer.setStage(6 - game.getPlayer()->getBridgeEnergy());
    if (game.getPlayer()->isAlive()) {
        std::cout << "\nCONGRATULATIONS! You saved the Star Whale!" << std::endl;
        renderer.setStage(7); // Victory Pose
        renderer.render();
    }
    else {
        renderer.render();
        std::cout << "\nGAME OVER. The whale faded away..." << std::endl;
    }

    return 0;
}