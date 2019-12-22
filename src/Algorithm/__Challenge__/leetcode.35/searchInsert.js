/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function searchInsert(nums, target) {
    const index = nums.indexOf(target);
    if(index != -1) return index;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] > target) return i;
    }
    return nums.length;
};