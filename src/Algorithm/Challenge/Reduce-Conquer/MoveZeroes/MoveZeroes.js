
class Solution {
    constructor(nums) {
        this.nums = nums;
        this.count = 0
    }
    execlut(nums) {
        for (let i = 0; i < this.nums.length - this.count; i++) {
            if (this.nums[i] != 0) continue;
            else {
                this.insertion(i);
                i--;
            }
        }
    };
    insertion(i) {
        let j = i
        while (j < this.nums.length - 1) {
            this.nums[j] = this.nums[++j]
        }
        this.nums[this.nums.length - 1] = 0;
        this.count++;
    }

}

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function (nums) {
    new Solution(nums).execlut()
};

moveZeroes([0,1,0,3,12]);