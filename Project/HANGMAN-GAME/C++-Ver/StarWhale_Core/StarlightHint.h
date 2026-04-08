/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Skills
Purpose: Declares the Starlight Hint skill class.
Filename: StarlightHint.h
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function prototypes
-----------------------------------------------------------*/

#ifndef STARLIGHT_HINT_H
#define STARLIGHT_HINT_H

#include "ISkill.h"

class StarlightHint : public ISkill {
public:
    // Returns the name of the skill as a C-string
    const char* getName() const override;

    // Uses the skill: Deducts energy and reveals a hint
    // (In a real game, this would interact with the Game Engine)
    void use(PlayerProfile& player) override;

    // Virtual destructor for safe inheritance
    virtual ~StarlightHint() {}
};
#endif