// src: https://leetcode.com/problems/remove-element/

class Solution {
    constructor(nums, val) {
        this.nums = nums;
        this.val = val;
    }
    get count() {
        let result = this.nums.length;
        this.nums.forEach(e => {
            if (e == this.val) result--;
        });
        return result;
    }
    // ideas: 减治法—减常因子，插入排序
    removeVal() {
        let len = nums.length;
        for (let i = 0; i < len; i++) {
            if (this.nums[i] != this.val) continue;
            for (let j = i; j < len - 1; j++) {
                this.nums[j] = this.nums[j + 1]
            }
            i--;
            len--;
        }
    }
    execult() {
        let result = this.count;
        this.removeVal();
        return result;
    }
}

/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    return new Solution(nums, val).execult()
};

removeElement([0, 1, 2, 2, 3, 0, 4, 2], 2)