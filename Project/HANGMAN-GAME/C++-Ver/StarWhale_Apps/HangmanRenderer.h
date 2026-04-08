/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Renderer
Purpose: Declares the class responsible for UI, console output, and visual effects.
Filename: HangmanRenderer.h
Version 0.1
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
-----------------------------------------------------------*/

#ifndef HANGMAN_RENDERER_H
#define HANGMAN_RENDERER_H

#include <string>

class HangmanRenderer {
private:
    int m_currentStage;
    bool m_useColor;

public:
    HangmanRenderer();

    void setStage(int stage);
    int getStage() const;

    void setUseColor(bool enabled);
    bool isColorEnabled() const;

    void renderTitle() const;
    void renderStage() const;
    void renderGameState(
        const std::string& playerName,
        int bridgeEnergy,
        int starPieces,
        const std::string& displayWord) const;
};

#endif