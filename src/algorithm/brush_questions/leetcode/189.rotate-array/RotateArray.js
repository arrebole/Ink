// 数组翻转问题
// ideas: 队列操作
class Solution {
    constructor(nums, k) {
        this.nums = nums;
        this.target = k;
    }
    execult() {
        for (let i = 0; i < this.target; i++) {
            this.nums.unshift(this.nums.pop())
        }
        return this.nums
    }
}

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
    return new Solution(nums, k).execult();
};