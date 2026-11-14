/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Skills
Purpose: Declares the Starlight Hint skill class.
Filename: StarlightHint.h
Version 0.3
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function prototypes
2026/11/13  use() returns bool; override revealsLetter()
-----------------------------------------------------------*/

#ifndef STARLIGHT_HINT_H
#define STARLIGHT_HINT_H

#include "ISkill.h"

class StarlightHint : public ISkill {
public:
    // Returns the name of the skill as a C-string
    const char* getName() const override;

    // Uses the skill: deducts energy; returns true if applied
    bool use(PlayerProfile& player) override;

    // This skill reveals one hidden letter
    bool revealsLetter() const override;

    // Virtual destructor for safe inheritance
    virtual ~StarlightHint() {}
};
#endif