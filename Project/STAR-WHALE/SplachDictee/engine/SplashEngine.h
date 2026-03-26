#ifndef SPLASHENGINE_H
#define SPLASHENGINE_H

#include <string>
#include <iostream>

using namespace std;

class SplashEngine {
private:

    string playerName;
    int playerId;


    string targetWord;      
    string wordMeaning;     
    string wittyHint;       
    

    string guessedLetters;  
    int triesLeft;          

public:
 
    SplashEngine(string name, int id);
    

    void loadMissions();  
    void play();         
    void saveProgress();  

  
    bool isWordGuessed();           
    string getHiddenWord();          
    string getGuessedLetters();      
    bool processGuess(char guess); 
    void setTargetWord(string word); 
};

#endif