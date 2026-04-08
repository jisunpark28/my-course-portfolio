/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Renderer
Purpose: Declares the class responsible for UI, console output, and visual effects.
Filename: WhaleRenderer.h
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/08  Add function prototypes
2026/04/11  Add functions for color mode
-----------------------------------------------------------*/

#ifndef WHALE_RENDERER_H
#define WHALE_RENDERER_H

class WhaleRenderer {
    int m_currentStage; // Track the number of failed attempts (0-6)
    bool m_useColor;
public:
    WhaleRenderer();

    // Updates the stage based on wrong guesses
    void setStage(int stage);

    // Renders the whale ASCII art to the console
    void render() const;

    // Returns current stage for testing
    int getStage() const;

    void setUseColor(bool);
    bool isColorEnabled() const;
};

#endif