/**
 * @param {string} word
 * @return {boolean}
 */
function detectCapitalUse(word) {
    if(filter(word, 0x41, 0x5A)
    || filter(word, 0x61, 0x7A)
    || filter(word.slice(0, 1), 0x41, 0x5A) && filter(word.slice(1), 0x61, 0x7A)
    ) return true;
    return false
}

function filter(s, lo, hi){
    for(let i = 0; i < s.length;i++){
        if(s.charCodeAt(i) > hi || s.charCodeAt(i) < lo ) return false;
    }
    return true;
}