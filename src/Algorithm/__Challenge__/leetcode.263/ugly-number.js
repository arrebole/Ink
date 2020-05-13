/**
 * @param {number} num
 * @return {boolean}
 */
function isUgly(num) {
    if (num <= 0) return false;

    while (num != 1) {
        if      (num%2 == 0)     num/=2;
        else if (num%3 == 0)     num/=3;
        else if (num%5 == 0)     num/=5;
        else                     return false;
    }

    return true;
}

console.time("isUgly");
isUgly(1369479539);
console.timeEnd("isUgly");