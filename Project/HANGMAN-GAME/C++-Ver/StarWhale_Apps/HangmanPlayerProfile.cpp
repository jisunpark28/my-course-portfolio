/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Data & State
Purpose: Implements the HangmanPlayerProfile class logic and state encapsulation.
Filename: HangmanPlayerProfile.cpp
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/07  Add Function Implementations
-----------------------------------------------------------*/

#include "HangmanPlayerProfile.h"

// Initialize player with 0 stars and 6 HP
HangmanPlayerProfile::HangmanPlayerProfile(std::string playerName)
    : name(playerName), starPieces(0), bridgeEnergy(6) {
}

//Getters
std::string HangmanPlayerProfile::getName() const {
    return name;
}

int HangmanPlayerProfile::getStarPieces() const {
    return starPieces;
}

int HangmanPlayerProfile::getBridgeEnergy() const {
    return bridgeEnergy;
}

// State Modifier - Increase score
void HangmanPlayerProfile::addStarPiece(int amount) {
    starPieces += amount;
}

// State Modifier - Decrease HP (min 0)
void HangmanPlayerProfile::decreaseEnergy() {
    if (bridgeEnergy > 0) {
        bridgeEnergy--;
    }
}

// State Modifier - Recover HP (max 6)
void HangmanPlayerProfile::healEnergy(int amount) {
    bridgeEnergy += amount;
    if (bridgeEnergy > 6) {
        bridgeEnergy = 6;
    }
}

// State Modifier - Check survival status
bool HangmanPlayerProfile::isAlive() const {
    return bridgeEnergy > 0;
}

// Add skill to inventory
void HangmanPlayerProfile::addSkill(std::unique_ptr<IHangmanSkill> newSkill) {
    skills.push_back(std::move(newSkill));
}