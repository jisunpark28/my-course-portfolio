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
2026/04/10  Add useEnergy feature to control the energy
-----------------------------------------------------------*/

#ifndef PLAYER_PROFILE_H
#define PLAYER_PROFILE_H

#include <string>
#include "ISkill.h"

class ISkill; // Forward declaration

struct SkillSlot {
    ISkill* m_skillPtr;
};

class PlayerProfile {
private:
    char* m_name;            // Player's name (Dynamic C-string)
    int m_starPieces;        // Score
    int m_bridgeEnergy;      // Remaining trials (HP)

    SkillSlot* m_inventory;
    int m_skillCount;
    int m_maxSkills;

    void cleanup();

public:
    PlayerProfile(const char* playerName);
    ~PlayerProfile();

    // Rule of Three: Prevent shallow copies
    PlayerProfile(const PlayerProfile&) = delete;
    PlayerProfile& operator=(const PlayerProfile&) = delete;

    // Getters
    const char* getName() const;
    int getStarPieces() const;
    int getBridgeEnergy() const;

    // State Modifiers
    void addStarPiece(int amount = 1);
    void decreaseEnergy();
    void healEnergy(int amount = 1);
    void useEnergy(int amount);
    bool isAlive() const;

    // Inventory Management
    void addSkill(ISkill* newSkill);
    int getSkillCount() const;
    ISkill* getSkill(int index) const;
};

#endif