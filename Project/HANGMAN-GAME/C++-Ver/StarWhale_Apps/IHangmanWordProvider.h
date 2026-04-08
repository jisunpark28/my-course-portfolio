/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Interface
Purpose: Declares the pure virtual interface for word provisioning.
Filename: IHangmanWordProvider.h
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/07  Add Pure Virtual Functions
-----------------------------------------------------------*/

#ifndef I_WORD_PROVIDER_H
#define I_WORD_PROVIDER_H

#include "HangmanWordData.h"

class IWordProvider {
public:

    virtual WordData getWord() = 0;
    virtual ~IWordProvider() = default;

};

#endif