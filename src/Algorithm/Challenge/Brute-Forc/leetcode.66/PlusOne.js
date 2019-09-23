class Solution {
    /**
     * @param {number[]} digits
     */
    constructor(digits) {
        this.digits = digits;
        this.len = digits.length;
    }

    carry() {
        for (let i = this.len - 1; i >= 0; i--) {
            if (this.digits[i] <= 9) return this.digits;

            this.digits[i] = 0;
            if (i == 0) this.digits.unshift(1)
            else this.digits[i - 1]++;
        }
        return this.digits;
    }

    plusOne() {
        this.digits[this.len - 1]++;
        return this.carry();
    }
}

/**
 * @param {number[]} digits
 */
function plusOne(digits) {
    const solution = new Solution(digits);
    return solution.plusOne()
}

console.log(plusOne([9]))