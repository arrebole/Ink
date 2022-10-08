/**
 * convertToTitle 返回它在Excel表中相对应的列名称
 * @param {number} n
 * @return {string}
 */
function convertToTitle(n) {
    let result = [];
    while (n > 0) {
        result.push(String.fromCharCode((n-1)%26 + 65));
        n = parseInt((n-1)/26);
    }
    return result.reverse().join("");
};

module.exports = convertToTitle