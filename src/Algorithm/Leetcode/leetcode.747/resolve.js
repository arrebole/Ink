// ideas: 暴力法-顺序查找


class Solution {
    constructor(nums) {
        this.nums = nums;
        this.maxIndex = 0;
        this.maxValue = nums[0];
    }
    findMaxValue() {
        this.nums.forEach((value, index) => {
            if (value > this.maxValue) {
                this.maxIndex = index;
                this.maxValue = this.nums[index];
            }
        });
    }

    maxIsTwoPow() {
        let result = this.maxIndex;
        this.nums.forEach((v, i) => {
            if (v * 2 > this.maxValue && i != this.maxIndex) {
                result = -1
            }
        })
        return result
    }
    answer() {
        this.findMaxValue()
        return this.maxIsTwoPow()
    }
}

/**
 * @param {number[]} nums
 * @return {number}
 */
function dominantIndex(nums) {
    if(nums.length < 2){
        return nums.length -1;
    }
    const solution = new Solution(nums)
    return solution.answer()
};

