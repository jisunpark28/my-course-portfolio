/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Renderer
Purpose: Declares the class responsible for UI, console output, and visual effects.
Filename: HangmanRenderer.h
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function prototypes
2026/04/11  Add functions for color mode
2026/11/13  Rename classes, files, and screen text to Word Hint Hangman
-----------------------------------------------------------*/

#ifndef HANGMAN_RENDERER_H
#define HANGMAN_RENDERER_H

class HangmanRenderer {
    int m_currentStage; // Track the number of failed attempts (0-6)
    bool m_useColor;
public:
    HangmanRenderer();

    // Updates the stage based on wrong guesses
    void setStage(int stage);

    // Renders the hangman ASCII art to the console
    void render() const;

    // Returns current stage for testing
    int getStage() const;

    void setUseColor(bool);
    bool isColorEnabled() const;
};

#endif