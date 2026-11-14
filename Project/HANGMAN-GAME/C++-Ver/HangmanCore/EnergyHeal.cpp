/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Skills
Purpose: Implements the logic for recovering lost bridge energy.
Filename: EnergyHeal.cpp
Version 0.4
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function implementations
2026/11/13  Return success from use(); remove console output
2026/11/13  Rename classes, files, and screen text to Word Hint Hangman
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "EnergyHeal.h"
#include "PlayerProfile.h"

const char* EnergyHeal::getName() const {
    return "Energy Heal";
}

bool EnergyHeal::use(PlayerProfile& player) {
    // Business Rule: recovers 2 bridge energy (cap handled in PlayerProfile)
    if (player.isAlive()) {
        player.healEnergy(2);
        return true;
    }
    return false;
}