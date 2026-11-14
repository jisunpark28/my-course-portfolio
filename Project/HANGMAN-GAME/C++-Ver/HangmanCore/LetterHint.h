/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Skills
Purpose: Declares the Letter Hint skill class.
Filename: LetterHint.h
Version 0.4
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function prototypes
2026/11/13  use() returns bool; override revealsLetter()
2026/11/13  Rename classes, files, and screen text to Word Hint Hangman
-----------------------------------------------------------*/

#ifndef LETTER_HINT_H
#define LETTER_HINT_H

#include "ISkill.h"

class LetterHint : public ISkill {
public:
    // Returns the name of the skill as a C-string
    const char* getName() const override;

    // Uses the skill: deducts energy; returns true if applied
    bool use(PlayerProfile& player) override;

    // This skill reveals one hidden letter
    bool revealsLetter() const override;

    // Virtual destructor for safe inheritance
    virtual ~LetterHint() {}
};
#endif