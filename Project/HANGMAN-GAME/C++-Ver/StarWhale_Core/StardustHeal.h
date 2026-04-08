/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Skills
Purpose: Declares the Stardust Heal skill class.
Filename: StardustHeal.h
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function prototypes
-----------------------------------------------------------*/

#ifndef SENECA_STARDUST_HEAL_H
#define SENECA_STARDUST_HEAL_H

#include "ISkill.h"

class StardustHeal : public ISkill {
public:
    // Returns the name of the skill
    const char* getName() const override;

    // Uses the skill: Recovers player energy
    void use(PlayerProfile& player) override;

    // Virtual destructor
    virtual ~StardustHeal() {}
};

#endif