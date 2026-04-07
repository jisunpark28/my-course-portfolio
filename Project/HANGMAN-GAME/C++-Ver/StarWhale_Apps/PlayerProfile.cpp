/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Data & State
Purpose: Implements the PlayerProfile class logic and state encapsulation.
Filename: PlayerProfile.cpp
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/07  Add Function Implementations
-----------------------------------------------------------*/

#include "PlayerProfile.h"

// Initialize player with 0 stars and 6 HP
PlayerProfile::PlayerProfile(std::string playerName)
    : name(playerName), starPieces(0), bridgeEnergy(6) {
}

//Getters
std::string PlayerProfile::getName() const {
    return name;
}

int PlayerProfile::getStarPieces() const {
    return starPieces;
}

int PlayerProfile::getBridgeEnergy() const {
    return bridgeEnergy;
}

// State Modifier - Increase score
void PlayerProfile::addStarPiece(int amount) {
    starPieces += amount;
}

// State Modifier - Decrease HP (min 0)
void PlayerProfile::decreaseEnergy() {
    if (bridgeEnergy > 0) {
        bridgeEnergy--;
    }
}

// State Modifier - Recover HP (max 6)
void PlayerProfile::healEnergy(int amount) {
    bridgeEnergy += amount;
    if (bridgeEnergy > 6) {
        bridgeEnergy = 6;
    }
}

// State Modifier - Check survival status
bool PlayerProfile::isAlive() const {
    return bridgeEnergy > 0;
}

// Add skill to inventory
void PlayerProfile::addSkill(std::unique_ptr<ISkill> newSkill) {
    skills.push_back(std::move(newSkill));
}