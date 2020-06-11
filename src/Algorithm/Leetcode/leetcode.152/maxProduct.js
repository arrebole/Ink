/**
 * maxProduct 乘积最大子序列
 * exploit: 动态规划
 * @param {number[]} nums
 * @return {number}
 */
function maxProduct(nums) {
    let result = Number.MIN_SAFE_INTEGER
    let [dp_max, dp_min] = [1, 1];

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] < 0) [dp_max, dp_min] = [dp_min, dp_max]

        dp_max = Math.max(nums[i], dp_max * nums[i])
        dp_min = Math.min(nums[i], dp_min * nums[i])

        result = Math.max(dp_max, result)
    }
    return result
};

module.exports = maxProduct;