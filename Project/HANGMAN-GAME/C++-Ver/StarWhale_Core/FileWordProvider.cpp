/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Word Providers
Purpose: Implements the file reading logic to provide words to the game engine.
Filename: FileWordProvider.cpp
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add fuction implementations
2026/04/09  Add function prototypes
2026/04/10  Add string header for getline fn.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include "FileWordProvider.h"

namespace {
    void trimRight(char* text) {
        if (!text) return;
        size_t len = std::strlen(text);
        while (len > 0 && (text[len - 1] == '\r' || text[len - 1] == ' ' || text[len - 1] == '\t')) {
            text[--len] = '\0';
        }
    }

    char* trimLeft(char* text) {
        if (!text) return text;
        while (*text == ' ' || *text == '\t') {
            ++text;
        }
        return text;
    }
}

FileWordProvider::FileWordProvider()
    : m_words(nullptr), m_count(0), m_isLoaded(false), m_seed(12345U) {
}

FileWordProvider::~FileWordProvider() {
    cleanup();
}

void FileWordProvider::cleanup() {
    if (m_words) {
        delete[] m_words;
        m_words = nullptr;
    }
    m_count = 0;
    m_isLoaded = false;
}

int FileWordProvider::customRand() {
    m_seed = m_seed * 1103515245U + 12345U;
    return static_cast<int>((m_seed / 65536U) % 32768U);
}

bool FileWordProvider::loadWords(const char* filename) {
    return load(filename);
}

bool FileWordProvider::load(const char* filename) {
    if (!filename) return false;

    std::ifstream file(filename);
    if (!file) return false;

    cleanup();

    char line[256];
    int tempCount = 0;

    while (file.getline(line, 256)) {
        trimRight(line);
        if (line[0] != '\0') {
            ++tempCount;
        }
    }

    if (tempCount == 0) return false;

    m_words = new WordData[tempCount];

    file.clear();
    file.seekg(0, std::ios::beg);

    while (file.getline(line, 256) && m_count < tempCount) {
        trimRight(line);
        if (line[0] == '\0') {
            continue;
        }

        char* delimiter = std::strchr(line, ':');
        if (!delimiter) delimiter = std::strchr(line, '|');

        if (delimiter) {
            *delimiter = '\0';
            trimRight(line);

            char* hint = trimLeft(delimiter + 1);
            trimRight(hint);

            std::strncpy(m_words[m_count].word, line, 49);
            m_words[m_count].word[49] = '\0';

            std::strncpy(m_words[m_count].hint, hint, 149);
            m_words[m_count].hint[149] = '\0';
        }
        else {
            // Also accept plain word-only line
            std::strncpy(m_words[m_count].word, line, 49);
            m_words[m_count].word[49] = '\0';

            std::strcpy(m_words[m_count].hint, "No hint available.");
        }

        ++m_count;
    }

    m_isLoaded = (m_count > 0);
    return m_isLoaded;
}

const char* FileWordProvider::getRandomWord() {
    if (!m_isLoaded || m_count == 0 || !m_words) return "";
    return m_words[customRand() % m_count].word;
}

const char* FileWordProvider::getHintForWord(const char* word) const {
    if (!m_isLoaded || !m_words || !word) return "No hint available.";

    for (int i = 0; i < m_count; i++) {
        if (std::strcmp(m_words[i].word, word) == 0) {
            return m_words[i].hint;
        }
    }
    return "No hint available.";
}

int FileWordProvider::wordCount() const {
    return m_count;
}