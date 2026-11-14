/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Interface
Purpose: Declares the pure virtual interface for word provisioning.
Filename: IWordProvider.h
Version 0.3
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/07  Add Pure Virtual Functions
2026/11/13  Align interface with real provider API (load, random word, hint, count)
-----------------------------------------------------------*/

#ifndef I_WORD_PROVIDER_H
#define I_WORD_PROVIDER_H

class IWordProvider {
public:

    // Load words from a source 
    virtual bool load(const char* source) = 0;

    // Return a random word, or nullptr if nothing is loaded
    virtual const char* getRandomWord() = 0;

    // Return the hint for the given word, or nullptr if not found
    virtual const char* getHintForWord(const char* word) const = 0;

    // Number of loaded words
    virtual int wordCount() const = 0;
    virtual ~IWordProvider() = default;

};
#endif