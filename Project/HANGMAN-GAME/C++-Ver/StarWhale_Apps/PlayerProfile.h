/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Data & State
Purpose: Declares the PlayerProfile class for managing player stats and inventory.
Filename: PlayerProfile.h
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/07  Add Function Prototypes
-----------------------------------------------------------*/

#ifndef PLAYER_PROFILE_H
#define PLAYER_PROFILE_H

#include <string>
#include <vector>
#include <memory>
#include "ISkill.h"

class ISkill; // Forward declaration

class PlayerProfile {
private:
    std::string name;       // Player's name
    int starPieces;         // Score (Collected stars)
    int bridgeEnergy;       // Remaining trials (HP)

    std::vector<std::unique_ptr<ISkill>> skills; // Skill inventory

public:
    // Constructor
    PlayerProfile(std::string playerName);

    // Getters
    std::string getName() const;         // Get player name
    int getStarPieces() const;           // Get current score
    int getBridgeEnergy() const;         // Get remaining HP

    // State Modifiers
    void addStarPiece(int amount = 1);   // Increase score
    void decreaseEnergy();               // Deduct HP on wrong guess
    void healEnergy(int amount = 1);     // Recover HP
    bool isAlive() const;                // Check if HP > 0

    // Inventory Management
    void addSkill(std::unique_ptr<ISkill> newSkill); // Add new skill
};

#endif