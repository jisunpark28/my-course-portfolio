/* Citation and Sources...
Hangman C++ Version: Word Hint Hangman
Module: Test
Purpose: HangmanGame tests using an injected fake word provider.
Filename: test_HangmanGame.cpp
Version 0.3
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/11/13  Add game tests with FakeWordProvider (dependency injection)
2026/11/13  Rename classes, files, and screen text to Word Hint Hangman
-----------------------------------------------------------*/

#include "pch.h"
#include "CppUnitTest.h"
#include "IWordProvider.h"
#include "HangmanGame.h"
#include "PlayerProfile.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// [Fake Object] Always returns "CAT" - no file needed
class FakeWordProvider : public IWordProvider {
public:
    bool load(const char*) override { return true; }
    const char* getRandomWord() override { return "CAT"; }
    const char* getHintForWord(const char*) const override { return "A small pet"; }
    int wordCount() const override { return 1; }
};

namespace HangmanTest
{
    // ID          Description              Steps                          Expected Result
    //
    // GT_001      New game display         Start game with "CAT"          Display "___", not over
    // GT_002      Win by guessing          Guess C, A, T                  Game over, alive, score 10
    // GT_003      Lose by wrong guesses    Guess 6 wrong letters          Game over, not alive
    // GT_004      Hint reveals a letter    Use skill 0 (Letter Hint)   Returns true, display "C__", HP 4
    TEST_CLASS(HangmanGameTests)
    {
    public:
        TEST_METHOD(GT_001)
        {
            FakeWordProvider fake;
            HangmanGame game(fake);
            Assert::IsTrue(game.startNewGame("unused", "Jisun"));
            Assert::AreEqual("___", game.getDisplayWord());
            Assert::IsFalse(game.isGameOver());
        }
        TEST_METHOD(GT_002)
        {
            FakeWordProvider fake;
            HangmanGame game(fake);
            game.startNewGame("unused", "Jisun");
            Assert::IsTrue(game.makeGuess('c'));   // lowercase also works
            Assert::IsTrue(game.makeGuess('A'));
            Assert::IsTrue(game.makeGuess('T'));
            Assert::IsTrue(game.isGameOver());
            Assert::IsTrue(game.getPlayer()->isAlive());
            Assert::AreEqual(10, game.getPlayer()->getStarPieces());
        }
        TEST_METHOD(GT_003)
        {
            FakeWordProvider fake;
            HangmanGame game(fake);
            game.startNewGame("unused", "Jisun");
            const char wrong[] = { 'X', 'Y', 'Z', 'Q', 'W', 'E' };
            for (char c : wrong) {
                Assert::IsFalse(game.makeGuess(c));
            }
            Assert::IsTrue(game.isGameOver());
            Assert::IsFalse(game.getPlayer()->isAlive());
        }
        TEST_METHOD(GT_004)
        {
            FakeWordProvider fake;
            HangmanGame game(fake);
            game.startNewGame("unused", "Jisun");
            Assert::IsTrue(game.useSkill(0));       // Letter Hint
            Assert::AreEqual("C__", game.getDisplayWord());
            Assert::AreEqual(4, game.getPlayer()->getBridgeEnergy());
        }
    };
}