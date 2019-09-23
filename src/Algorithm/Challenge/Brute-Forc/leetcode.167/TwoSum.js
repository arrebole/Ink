// ideas: 暴力法—穷举查找
class Solution {
    constructor(nums, target) {
        this.nums = nums;
        this.target = target;
        this.lo = 0;
        this.hi = 0;
    }
    get lastIndex() {
        return this.nums.length - 1;
    }
    get result() {
        return [this.lo + 1, this.hi + 1]
    }
    isEqTarget() {
        let sum = this.nums[this.lo] + this.nums[this.hi];
        return sum == this.target;
    }
    twoSum() {
        while (this.lo < this.nums.length) {
            this.hi = this.lastIndex
            while (this.hi > this.lo) {
                if (this.isEqTarget()) return this.result;
                this.hi--
            }
            this.lo++
        }
    }
}

/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (numbers, target) {
    return new Solution(numbers, target).twoSum()
};