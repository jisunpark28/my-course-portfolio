/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Interface
Purpose: Declares the pure virtual interface for player skills and items.
Filename: ISkill.h
Version 0.3
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/07  Add Class
2026/11/13  Add virtual, modify use() returns bool 
-----------------------------------------------------------*/

#ifndef I_SKILL_H
#define I_SKILL_H

class PlayerProfile;

class ISkill {
public:
    virtual const char* getName() const = 0;

    // Applies the skill; returns true if it was actually used
    virtual bool use(PlayerProfile& player) = 0;

    // Does this skill reveal a hidden letter? Default: no
    virtual bool revealsLetter() const { return false; }
    virtual ~ISkill() = default;
};
#endif