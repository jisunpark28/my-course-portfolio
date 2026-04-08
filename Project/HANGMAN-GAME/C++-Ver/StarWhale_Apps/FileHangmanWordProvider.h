/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Word Providers
Purpose: Declares the class for reading words from a text file.
Filename: FileHangmanWordProvider.h
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
-----------------------------------------------------------*/

#ifndef FILE_HANGMAN_WORD_PROVIDER_H
#define FILE_HANGMAN_WORD_PROVIDER_H

#include <random>
#include <string>
#include <vector>
#include "IHangmanWordProvider.h"

class FileHangmanWordProvider : public IHangmanWordProvider {
private:
    std::vector<HangmanWordData> m_words;
    std::mt19937 m_rng;

public:
    FileHangmanWordProvider();

    bool loadWords(const std::string& filePath);
    HangmanWordData getWord() override;
    std::string getHintForWord(const std::string& word) const;
    bool isLoaded() const;
    std::size_t wordCount() const;
};

#endif