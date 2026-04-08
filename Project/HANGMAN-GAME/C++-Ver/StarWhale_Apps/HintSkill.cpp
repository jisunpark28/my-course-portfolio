/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Skills
Purpose: Implements the logic for revealing a hidden letter on the board.
Filename: HintSkill.cpp
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
-----------------------------------------------------------*/

#include "HintSkill.h"
#include "HangmanPlayerProfile.h"

std::string HintSkill::getName() const {
    return "Hint Skill";
}

void HintSkill::use(HangmanPlayerProfile& player) {
    // Minimal skill rule for skeleton implementation:
    // using hint consumes one energy if player is alive.
    if (player.isAlive()) {
        player.decreaseEnergy();
    }
}