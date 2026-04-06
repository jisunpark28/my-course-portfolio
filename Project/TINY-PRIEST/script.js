/**
 * Handles character interaction and updates the dialogue box.
 * @param {string} character - The ID of the character clicked.
 */
function handleInteract(character) {
    const dialogueBox = document.getElementById('dialogue-box');
    
    // Simple logic for character responses
    switch(character) {
        case 'priest':
            dialogueBox.innerText = "Father: Peace be with you! Shall we explore the church together?";
            break;
        case 'nun':
            dialogueBox.innerText = "Sister: Hello there! Wishing you a day full of blessings.";
            break;
        default:
            dialogueBox.innerText = "Click a character to interact!";
    }

   
}