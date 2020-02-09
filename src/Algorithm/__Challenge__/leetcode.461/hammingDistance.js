/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
function hammingDistance(x, y) {
    let result = 0
    const xor = x ^ y;
    const bin = xor.toString(2);
    for(const i of bin){
        if (i == '1') result++;
    }
    return result
};