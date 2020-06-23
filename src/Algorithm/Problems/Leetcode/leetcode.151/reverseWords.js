/**
 * @param {string} str
 * @return {string}
 */
var reverseWords = function(str) {
    return str.split(" ").filter(ch => ch != "").reverse().join(" ")
};