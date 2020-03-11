
function longestPalindrome(aStr) {
    let result = 0;
    for (const [k, v] of createCharTable(aStr)) {
        result += Number.parseInt(v / 2);
    }
    return result < aStr.length ? result + 1 : result;
}

function createCharTable(aStr) {
    const result = new Map();
    for (const char of aStr) {
        if (result.has(char)) result.set(char, result.get(char) + 1);
        else result.set(char, 0);
    }
    return result;
}