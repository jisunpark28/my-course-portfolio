/**
 * [Reflection Note]
 * Unlike C or Bash, where I had to manually iterate through arrays and manage 
 * specific indices for character comparison, JavaScript simplifies this process drastically.
 * Using built-in methods like .includes() and leveraging Closures for encapsulation 
 * made the implementation clean and simple.
 * It feels bittersweet to see how much "heavy lifting" is abstracted away in JS,
 * compared to the granular control required in lower-level languages.
 */



const prompt = require('prompt-sync')();

function hangman(secretWord){
    return function(guessLetter){
        if(secretWord.includes(guessLetter)){
            return true;
        }
            return false;
    }
}

var game = hangman("javascript");

var userGuessLetter = prompt("Enter your guess (one letter) >> ");

console.log("Your guess result: " + game(userGuessLetter));
