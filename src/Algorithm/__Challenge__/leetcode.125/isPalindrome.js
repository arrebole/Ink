/**
 * @param {string} s
 * @return {boolean}
 */
function isPalindrome(s) {
    if (s.length <= 1) return true;
    const array = s
        .toLowerCase()
        .split("")
        .filter(s=>filter(s))

    let lo = 0, hi = array.length - 1;
    while (lo < hi) {
        if (array[lo++] != array[hi--]) return false
    }
    return true;
};

function filter(s) {
    return (s.charCodeAt(0) >= 0x61 && s.charCodeAt(0) <= 0x7A)
        || (s.charCodeAt(0) >= 0x30 && s.charCodeAt(0) <= 0x39)
}

module.exports = isPalindrome