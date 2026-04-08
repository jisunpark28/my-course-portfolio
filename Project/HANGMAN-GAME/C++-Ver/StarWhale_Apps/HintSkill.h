/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Skills
Purpose: Declares the Starlight Hint skill class.
Filename: HintSkill.h
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
-----------------------------------------------------------*/

#ifndef HINT_SKILL_H
#define HINT_SKILL_H

#include "IHangmanSkill.h"

class HintSkill : public IHangmanSkill {
public:
    std::string getName() const override;
    void use(HangmanPlayerProfile& player) override;
    ~HintSkill() override = default;
};

#endif