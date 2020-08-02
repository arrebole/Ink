// searchRange 在排序数组中查找元素的第一个和最后一个位置
// expolit: 减治-二分查找；T(n) = O(log N)
function searchRange(nums, target) {
    return [leftIndexOf(nums, target), rightIndexOf(nums, target)]
};

function leftIndexOf(nums, target) {
    let lo = 0, hi = nums.length -1;
    while(lo < hi){
        const mid = Math.floor((lo + hi)/2);
        if(nums[mid] == target){
            lo = mid
            break
        }
        if(nums[mid] > target) hi = mid -1;
        if(nums[mid] < target) lo = mid + 1;
    }
    if(nums[lo] != target) return -1;
    while( nums[lo-1] == target) lo--;
    return lo;
}

function rightIndexOf(nums, target) {
    let lo = 0, hi = nums.length -1;
    while(lo < hi){
        const mid = Math.ceil((lo + hi)/2);
        if(nums[mid] == target){
            hi = mid
            break
        }
        if(nums[mid] > target) hi = mid -1;
        if(nums[mid] < target) lo = mid + 1;
    }
    if(nums[hi] != target) return -1;
    while( nums[hi+1] == target) hi++;
    return hi;
}

searchRange([5,7,7,8,8,10],6)