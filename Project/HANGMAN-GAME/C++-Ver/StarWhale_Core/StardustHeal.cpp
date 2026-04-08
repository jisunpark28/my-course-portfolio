/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Skills
Purpose: Implements the logic for recovering lost bridge energy.
Filename: StardustHeal.cpp
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function implementations
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StardustHeal.h"
#include "PlayerProfile.h"

const char* StardustHeal::getName() const {
    return "Stardust Heal";
}

void StardustHeal::use(PlayerProfile& player) {
    // Business Rule: Stardust Heal recovers 2 bridge energy
    // Assuming healEnergy() inside PlayerProfile handles the max HP cap (6)
    if (player.isAlive()) {
        player.healEnergy(2);
        std::cout << "[Skill] Stardust Heal used! (Energy +2)" << std::endl;
    }
    else {
        std::cout << "[Skill] Cannot heal a fallen player!" << std::endl;
    }
}