/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Skills
Purpose: Implements the logic for recovering lost bridge energy.
Filename: HealSkill.cpp
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
-----------------------------------------------------------*/

#include "HealSkill.h"
#include "HangmanPlayerProfile.h"

std::string HealSkill::getName() const {
    return "Heal Skill";
}

void HealSkill::use(HangmanPlayerProfile& player) {
    // Minimal skill rule for skeleton implementation:
    // heal by one energy when player is still alive.
    if (player.isAlive()) {
        player.healEnergy(1);
    }
}