/**
 * [Reflection Note]
 * Unlike C or Bash, where I had to manually iterate through arrays and manage 
 * specific indices for character comparison, JavaScript simplifies this process drastically.
 * Using built-in methods like .includes() and leveraging Closures for encapsulation 
 * made the implementation clean and simple.
 * It feels bittersweet to see how much "heavy lifting" is abstracted away in JS,
 * compared to the granular control required in lower-level languages.
 */


function createHangman(secretWord) {
    const word = secretWord.toLowerCase();
    let guessedLetters = [];
    let attemptsLeft = 6;

    return {
        // Returns the current view of the word (e.g., "j a _ a _ _ _ _ _ _")
        getDisplayView: () => word.split('').map(c => (guessedLetters.includes(c) || c === ' ' ? c : '_')).join(' '),

        // Processes the user's guess and updates attempts
        processGuess: function (letter) {
            letter = letter.toLowerCase();
            if (!letter || guessedLetters.includes(letter)) return false;
            guessedLetters.push(letter);
            if (!word.includes(letter)) attemptsLeft--;
            return true;
        },

        // Checks if the game is won or lost
        isFinished: () => word.split('').every(c => guessedLetters.includes(c) || c === ' ') || attemptsLeft <= 0,
        getAttempts: () => attemptsLeft,
        getGuessedLetters: () => guessedLetters,
        isWin: () => word.split('').every(c => guessedLetters.includes(c) || c === ' ')
    };
}

// Initialize game and DOM elements
let game = createHangman("javascript");
const display = document.querySelector("#word-display");
const btn = document.querySelector("#guess-btn");
const input = document.querySelector("#letter-input");
const petals = document.querySelectorAll("#petals-container .petal");
const attemptsSpan = document.querySelector("#attempts");
const guessedLettersSpan = document.querySelector("#guessed-letters");

// Updates the UI based on the current game state
function updateUI() {
    display.innerHTML = game.getDisplayView();
    attemptsSpan.innerHTML = game.getAttempts();
    guessedLettersSpan.innerHTML = game.getGuessedLetters().join(', ') || "-";

    const currentAttempts = game.getAttempts();
    // Hide petals based on failed attempts (index 0 to 5)
    petals.forEach((petal, index) => {
        if (index < (6 - currentAttempts)) {
            petal.classList.add("petal-hidden");
        } else {
            petal.classList.remove("petal-hidden");
        }
    });
}

// Event listener for the guess button
btn.addEventListener("click", () => {
    const letter = input.value;
    if (letter && !game.isFinished()) {
        game.processGuess(letter);
        updateUI();

        // Show result message after the final guess
        if (game.isFinished()) {
            setTimeout(() => {
                alert(game.isWin() ? "Congratulations! You saved the flower! ✨" : "Game Over! The flower has lost its petals. 🥀");
            }, 100);
        }
    }
    input.value = "";
    input.focus();
});

// Event listener for the 'Enter' key to improve efficiency
input.addEventListener("keypress", (e) => {
    if (e.key === "Enter") btn.click();
});

// Reset game logic
document.querySelector("#reset-btn").addEventListener("click", () => {
    game = createHangman("javascript");
    updateUI();
    input.focus();
});

// Set initial UI state
window.onload = updateUI;

const resetBtn = document.querySelector("#reset-btn");

resetBtn.addEventListener("mouseover", () => {
    // Check if the game is NOT finished yet
    if (!game.isFinished()) {
        // Change position to absolute to move freely within the viewport
        resetBtn.style.position = "absolute";

        // Calculate random coordinates (keeping it within the visible screen)
        const x = Math.random() * (window.innerWidth - resetBtn.clientWidth);
        const y = Math.random() * (window.innerHeight - resetBtn.clientHeight);

        // Apply new coordinates
        resetBtn.style.left = `${x}px`;
        resetBtn.style.top = `${y}px`;
    }
});

// Reset button position when a new game actually starts
function resetBtnPosition() {
    resetBtn.style.position = "relative";
    resetBtn.style.left = "0";
    resetBtn.style.top = "0";
}

// Update your existing reset-btn click listener
resetBtn.addEventListener("click", () => {
    game = createHangman("javascript");
    resetBtnPosition(); // Bring the button back to its original spot
    updateUI();
    input.focus();
});