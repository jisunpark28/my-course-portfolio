/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Entry Point
Purpose: Initializes dependencies and starts the Star Whale application.
Filename: main.cpp
Version 0.4
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/09  Implement the main code
2026/04/10  Add hint feature
2026/11/13  Inject FileWordProvider into game (dependency injection); Print skill results in UI layer
2026/11/13  Choose Oracle provider with file fallback
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "StarWhaleGame.h"
#include "WhaleRenderer.h"
#include "StarlightHint.h"
#include "StardustHeal.h"
#include "PlayerProfile.h"
#include "FileWordProvider.h"
#include "OracleWordProvider.h"

int main() {
    // Choose word source: Oracle first, file as fallback
    OracleWordProvider oracleProvider;
    FileWordProvider fileProvider;

    IWordProvider* provider = &fileProvider;
    const char* source = "words.txt";

    if (oracleProvider.load("db_config.txt")) {
        provider = &oracleProvider;
        source = "db_config.txt";
        std::cout << "[DB] Connected to Oracle. Words loaded: "
            << oracleProvider.wordCount() << std::endl;
    }
    else {
        std::cout << "[DB] Oracle unavailable. Using words.txt instead." << std::endl;
    }

    StarWhaleGame game(*provider);
    WhaleRenderer renderer;
    char playerName[50];
    char guess;

    std::cout << "--- Welcome to Star Whale Hangman ---" << std::endl;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    // Start game with a words file
    if (!game.startNewGame(source, playerName)) {
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
            if (game.useSkill(0))
                std::cout << ">> Starlight Hint used! (Energy -2)" << std::endl;
            else
                std::cout << ">> Not enough energy for a hint." << std::endl;
        }
        else if (guess == '2') {
            if (game.useSkill(1))
                std::cout << ">> Stardust Heal used! (Energy +2)" << std::endl;
            else
                std::cout << ">> Cannot heal right now." << std::endl;
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