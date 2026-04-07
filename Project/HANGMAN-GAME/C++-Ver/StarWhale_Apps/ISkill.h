/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Interface
Purpose: Declares the pure virtual interface for player skills and items.
Filename: ISkill.h
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/07  Add Class
-----------------------------------------------------------*/

#ifndef I_SKILL_H
#define I_SKILL_H

#include <string>

class PlayerProfile;

class ISkill {
public:
    virtual std::string getName() const = 0;
    virtual void use(PlayerProfile& player) = 0;
    virtual ~ISkill() = default;
};

#endif