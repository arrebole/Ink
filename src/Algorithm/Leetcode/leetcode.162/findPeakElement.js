/**
 * findPeakElement 寻找峰值
 * exploit 二分搜索
 * @param {number[]} nums
 * @return {number}
 */
function findPeakElement(nums) {
    let lo = 0, hi = nums.length - 1
    while( lo <  hi){
        let mid = parseInt((lo + hi)/2)
        // 递增时，峰值在右， 递减时 峰值在左。
        if(nums[mid] > nums[mid+1]) hi = mid;
        else lo = mid + 1;
    }
    return lo;
};

module.exports = findPeakElement;