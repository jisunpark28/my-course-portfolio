#include "SplashEngine.h"
#include <iostream>
#include <string>

using namespace std;

SplashEngine::SplashEngine(string name, int id) {
    playerName = name;
    playerId = id;
    
    targetWord = "OCEAN"; 
    
    wordMeaning = "The blue area covering 70% of the Earth";
    wittyHint = "A giant bowl of salty water!";
    
    triesLeft = 6;
    guessedLetters = "";
}

void SplashEngine::loadMissions() {
}


void SplashEngine::play() {

    cout << "\n========================================" << endl;
    cout << " ✨ Hello " << playerName << "! Welcome to SplashDictee! 🐋 " << endl;
    cout << "       Let's have some fun guessing!    " << endl;
    cout << "========================================" << endl;

    cout << "\n🐋 [Meaning] " << wordMeaning << endl;
    cout << "✨ [Hint]    " << wittyHint << endl;

    while (triesLeft > 0 && !isWordGuessed()) {
        cout << "\n----------------------------------------" << endl;
        cout << "Current Word: " << getHiddenWord() << endl;
        cout << "Tries left:   " << triesLeft << endl;
        cout << "Guessed:      " << getGuessedLetters() << endl;

        char guess;
        cout << ">> Pick a letter: ";
        cin >> guess;

        guess = toupper(guess); 

        if (processGuess(guess)) {

            cout << "✨ Great! '" << guess << "' is in there!" << endl;
        } else {
            cout << "Sorry, '" << guess << "' is not the one." << endl;
        }
    }


    cout << "\n========================================" << endl;
    if (isWordGuessed()) {
    
        cout << "🐋 AMAZING! You got it right! ✨" << endl;
        cout << "The word was indeed: " << targetWord << endl;
    } else {
        cout << "Don't worry, you'll get it next time!" << endl;
        cout << "The hidden word was: " << targetWord << endl;
    }
    cout << "========================================" << endl;
}


void SplashEngine::saveProgress() {

}

void SplashEngine::setTargetWord(string word) {
    if (!word.empty()) targetWord = word;
}

bool SplashEngine::isWordGuessed() {
    for (char c : targetWord) {
        if (guessedLetters.find(c) == string::npos) {
            return false;
        }
    }
    return true;
}

string SplashEngine::getHiddenWord() {
    string display = "";
    for (char c : targetWord) {
        if (guessedLetters.find(c) != string::npos) {
            display += c;
            display += " ";
        } else {
            display += "_ ";
        }
    }
    return display;
}

string SplashEngine::getGuessedLetters() {
    return guessedLetters;
}

bool SplashEngine::processGuess(char guess) {
    if (guessedLetters.find(guess) != string::npos) {
        cout << ">> You already tried '" << guess << "'!" << endl;
        return true; 
    }

    guessedLetters += guess;

    if (targetWord.find(guess) == string::npos) {
        triesLeft--;
        return false;
    }
    return true;
}