// NumArray 区间内元素的总和
class NumArray {
    /**
     * @param {number[]} nums
     */
    constructor(nums) {
        this.sums = this.createSums(nums);
    }
    // createSums 创建一个总和表 用于加速多次sumRange调用
    // expolit： 时空权衡-输入增强
    createSums(nums) {
        const sums = new Array(nums.length);
        if (nums.length == 0) return sums

        sums[0] = nums[0]
        for (let i = 1; i < nums.length; i++) {
            sums[i] = nums[i] + sums[i - 1];
        }
        return sums
    }

    //sumRang 返回索引区间内元素的总和 
    sumRange(i, j) {
        if (i == 0) return this.sums[j];
        return this.sums[j] - this.sums[i - 1];
    }

};