/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Word Providers
Purpose: Implements the file reading logic to provide words to the game engine.
Filename: FileHangmanWordProvider.cpp
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
-----------------------------------------------------------*/

#include "FileHangmanWordProvider.h"

#include <fstream>

namespace {
std::string trim(const std::string& value) {
    const std::size_t begin = value.find_first_not_of(" \t\r\n");
    if (begin == std::string::npos) {
        return "";
    }
    const std::size_t end = value.find_last_not_of(" \t\r\n");
    return value.substr(begin, end - begin + 1);
}
}

FileHangmanWordProvider::FileHangmanWordProvider() : m_rng(std::random_device{}()) {
}

bool FileHangmanWordProvider::loadWords(const std::string& filePath) {
    m_words.clear();

    std::ifstream input(filePath);
    if (!input.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(input, line)) {
        line = trim(line);
        if (line.empty()) {
            continue;
        }

        HangmanWordData item{};
        const std::size_t firstSep = line.find(':');
        const std::size_t secondSep = (firstSep == std::string::npos) ? std::string::npos : line.find(':', firstSep + 1);

        if (firstSep == std::string::npos) {
            item.word = trim(line);
            item.meaning = "No hint available.";
            item.example = "";
        }
        else if (secondSep == std::string::npos) {
            item.word = trim(line.substr(0, firstSep));
            item.meaning = trim(line.substr(firstSep + 1));
            item.example = "";
        }
        else {
            item.word = trim(line.substr(0, firstSep));
            item.meaning = trim(line.substr(firstSep + 1, secondSep - firstSep - 1));
            item.example = trim(line.substr(secondSep + 1));
        }

        if (!item.word.empty()) {
            m_words.push_back(item);
        }
    }

    return !m_words.empty();
}

HangmanWordData FileHangmanWordProvider::getWord() {
    if (m_words.empty()) {
        return {"", "No hint available.", ""};
    }

    std::uniform_int_distribution<std::size_t> dist(0, m_words.size() - 1);
    return m_words[dist(m_rng)];
}

std::string FileHangmanWordProvider::getHintForWord(const std::string& word) const {
    for (const HangmanWordData& item : m_words) {
        if (item.word == word) {
            if (!item.meaning.empty()) {
                return item.meaning;
            }
            if (!item.example.empty()) {
                return item.example;
            }
            break;
        }
    }
    return "No hint available.";
}

bool FileHangmanWordProvider::isLoaded() const {
    return !m_words.empty();
}

std::size_t FileHangmanWordProvider::wordCount() const {
    return m_words.size();
}