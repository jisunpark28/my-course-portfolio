/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Word Providers
Purpose: Loads words and hints from an Oracle table via OCCI.
Filename: OracleWordProvider.h
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/11/13  Initial File
-----------------------------------------------------------*/

#ifndef ORACLE_WORD_PROVIDER_H
#define ORACLE_WORD_PROVIDER_H

#include <string>
#include <vector>
#include "IWordProvider.h"

class OracleWordProvider : public IWordProvider {
    struct Entry {
        std::string word;
        std::string hint;
    };
    std::vector<Entry> m_entries;

    // Reads user, password, connect from a key=value file
    static bool readConfig(const char* path, std::string& user,
        std::string& password, std::string& connect);

public:
    // source = path to db_config.txt
    bool load(const char* source) override;
    const char* getRandomWord() override;
    const char* getHintForWord(const char* word) const override;
    int wordCount() const override;
};

#endif