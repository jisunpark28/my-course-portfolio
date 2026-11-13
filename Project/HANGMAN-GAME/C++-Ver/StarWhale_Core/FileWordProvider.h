/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Word Providers
Purpose: Declares the class for reading words from a text file.
Filename: FileWordProvider.h
Version 0.3
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function prototypes
2026/04/10  Add function prototypes
2026/11/13  Implement IWordProvider
-----------------------------------------------------------*/

#ifndef FILE_WORD_PROVIDER_H
#define FILE_WORD_PROVIDER_H
#include "IWordProvider.h"
#include "WordData.h"

class FileWordProvider : public IWordProvider {
    WordData* m_words;    // Single dynamic block for all words
    int m_count;          // Total number of words
    bool m_isLoaded;
    unsigned int m_seed;  // Seed for LCG random generator

    void cleanup();
    int customRand();

public:
    FileWordProvider();
    ~FileWordProvider() override;

    // Rule of Three: Prevent shallow copy
    FileWordProvider(const FileWordProvider&) = delete;
    FileWordProvider& operator=(const FileWordProvider&) = delete;

    // IWordProvider
    bool load(const char* source) override;
    const char* getRandomWord() override;
    const char* getHintForWord(const char* word) const override;
    int wordCount() const override;

};

#endif