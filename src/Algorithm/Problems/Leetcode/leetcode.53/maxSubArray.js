

/**
 * maxSubArray 贪心解具有最大和的连续子数组
 * @param {number[]} nums
 * @return {number}
 */
function maxSubArray(nums) {
    let [currSum, maxSum] = [nums[0], nums[0]]
    for (let i = 1; i < nums.length; i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
};

function max(a, b){
    return a > b ? a : b;
}

module.exports = maxSubArray