#pragma once
/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Data & State
Purpose: Defines the structure for storing word, meaning, and example data.
Filename: WordData.h
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/07  Add Struct
2026/04/10  Modified the variables
-----------------------------------------------------------*/

#ifndef WORD_DATA_H
#define WORD_DATA_H

struct WordData {
    char word[50];
    char hint[150];
};

#endif