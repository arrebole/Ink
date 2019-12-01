/**
 * @param {number[]} nums
 */
function pivotIndex(nums) {
    for (let i = 0; i < nums.length; i++) {
        const LeftSum = arraySum(nums, 0, i - 1);
        const RightSum = arraySum(nums, i + 1, nums.length - 1)
        if (LeftSum == RightSum) {
            return i;
        }
    }
    return -1;
};

function arraySum(aArray, start, end) {
    let result = 0;
    while (start <= end) {
        result += aArray[start++];
    }
    return result;
}