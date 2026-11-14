/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Skills
Purpose: Implements the logic for revealing a hidden letter on the board.
Filename: LetterHint.cpp
Version 0.4
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function implementation
2026/11/13  Return success from use(); remove console output
2026/11/13  Rename classes, files, and screen text to Word Hint Hangman
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "LetterHint.h"
#include "PlayerProfile.h"

const char* LetterHint::getName() const {
    return "Letter Hint";
}

bool LetterHint::use(PlayerProfile& player) {
    if (player.getBridgeEnergy() >= 2) {
        player.useEnergy(2);
        return true;
    }
    return false;
}

bool LetterHint::revealsLetter() const {
    return true;      
}