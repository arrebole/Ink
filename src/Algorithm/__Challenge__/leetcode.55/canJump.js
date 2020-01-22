/**
 * @param {number[]} nums
 * @return {boolean}
 */
function canJump(nums) {
    let target = nums.length - 1;
    for (let i = target; i >= 0; i--) {
        if ((nums[i] + i) >= target) target = i;
    }
    return target == 0
};