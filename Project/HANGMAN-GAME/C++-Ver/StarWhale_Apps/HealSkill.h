/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Skills
Purpose: Declares the Stardust Heal skill class.
Filename: HealSkill.h
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
-----------------------------------------------------------*/

#ifndef HEAL_SKILL_H
#define HEAL_SKILL_H

#include "IHangmanSkill.h"

class HealSkill : public IHangmanSkill {
public:
    std::string getName() const override;
    void use(HangmanPlayerProfile& player) override;
    ~HealSkill() override = default;
};

#endif