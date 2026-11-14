/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Skills
Purpose: Implements the logic for revealing a hidden letter on the board.
Filename: StarlightHint.cpp
Version 0.3
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function implementation
2026/11/13  Return success from use(); remove console output
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "StarlightHint.h"
#include "PlayerProfile.h"

const char* StarlightHint::getName() const {
    return "Starlight Hint";
}

bool StarlightHint::use(PlayerProfile& player) {
    if (player.getBridgeEnergy() >= 2) {
        player.useEnergy(2);
        return true;
    }
    return false;
}

bool StarlightHint::revealsLetter() const {
    return true;      
}