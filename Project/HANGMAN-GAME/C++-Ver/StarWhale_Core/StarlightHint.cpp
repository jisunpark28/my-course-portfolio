/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Skills
Purpose: Implements the logic for revealing a hidden letter on the board.
Filename: StarlightHint.cpp
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function implementation
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StarlightHint.h"
#include "PlayerProfile.h"

const char* StarlightHint::getName() const {
    return "Starlight Hint";
}

void StarlightHint::use(PlayerProfile& player) {
    if (player.getBridgeEnergy() >= 2) {
        player.useEnergy(2);
        std::cout << "[Skill] Starlight Hint used! (Energy -2)" << std::endl;
    }
    else {
        std::cout << "[Skill] Not enough energy to use Starlight Hint!" << std::endl;
    }
}