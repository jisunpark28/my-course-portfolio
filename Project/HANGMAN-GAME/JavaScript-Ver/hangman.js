/**
 * [Reflection Note]
 * Unlike C or Bash, where I had to manually iterate through arrays and manage 
 * specific indices for character comparison, JavaScript simplifies this process drastically.
 * Using built-in methods like .includes() and leveraging Closures for encapsulation 
 * made the implementation clean and simple.
 * It feels bittersweet to see how much "heavy lifting" is abstracted away in JS,
 * compared to the granular control required in lower-level languages.
 */

const wordData = [
    { word: "javascript", hint: "The programming language of the Web" },
    { word: "html", hint: "The standard markup language used to define the structure and content of web pages" },
    { word: "css", hint: "The language used to define the design, style, and layout of web pages" },
    { word: "dom", hint: "The programming interface that allows JavaScript to manipulate HTML documents (Document Object Model)" },
    { word: "closure", hint: "A feature in JavaScript where an inner function has access to the outer function's variables" },
    { word: "function", hint: "A block of code designed to perform a particular task, often called a subprogram" },
    { word: "array", hint: "A data structure used to store multiple values in a single variable sequentially" },
    { word: "object", hint: "A JavaScript data type consisting of key-value pairs" },
    { word: "event", hint: "An action or occurrence recognized by the browser, such as a user click or keyboard input" },
    { word: "selector", hint: "A pattern used in CSS to select the HTML elements you want to style" },
    { word: "margin", hint: "The space outside the border of an element in the CSS Box Model" },
    { word: "padding", hint: "The space inside the border of an element in the CSS Box Model" },
    { word: "attribute", hint: "A property that provides additional information about an HTML element (e.g., id, class, src)" },
    { word: "element", hint: "A complete building block of HTML, from the start tag to the end tag" },
    { word: "validation", hint: "The process of checking if the data entered by a user in a form is correct" },
    { word: "regex", hint: "A sequence of characters that forms a search pattern, used for matching or validating strings" },
    { word: "string", hint: "A built-in JavaScript object and data type used to represent text data" },
    { word: "boolean", hint: "A data type that can only have one of two values: true or false" },
    { word: "constructor", hint: "A special function used to create and initialize objects" },
    { word: "form", hint: "An HTML container used to collect user input and send it to a server" }
];

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
let game; 
const display = document.querySelector("#word-display");
const btn = document.querySelector("#guess-btn");
const input = document.querySelector("#letter-input");
const petals = document.querySelectorAll("#petals-container .petal");
const attemptsSpan = document.querySelector("#attempts");
const guessedLettersSpan = document.querySelector("#guessed-letters");
const resetBtn = document.querySelector("#reset-btn");
const hintDisplay = document.querySelector("#hint-display");

function initGame() {
    const randomIndex = Math.floor(Math.random() * wordData.length);
    const randomData = wordData[randomIndex];
    game = createHangman(randomData.word);
    if (hintDisplay) {
        hintDisplay.innerText = "💡 Hint: " + randomData.hint;
    }
    updateUI();
    resetBtnPosition();
    input.value = "";
    input.focus();
}

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

input.addEventListener("input", (e) => {
    // Accept letters only
    e.target.value = e.target.value.replace(/[^a-zA-Z]/g, '');
});

// Event listener for the 'Enter' key to improve efficiency
input.addEventListener("keypress", (e) => {
    if (e.key === "Enter") btn.click();
});

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

// Reset game logic
resetBtn.addEventListener("click", () => {
    initGame();
});

window.onload = initGame;
