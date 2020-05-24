
/**
 * 
 * @param {string[]} letters 
 * @param {string} target 
 */
function nextGreatestLetter(letters, target){
    letters = letters.sort((a, b) => a.charCodeAt(0) - b.charCodeAt(0));
    for(const char of letters) {
        if(char > target) return char;
    }
    return letters[0];
}

nextGreatestLetter(["c","f","j"], "j")