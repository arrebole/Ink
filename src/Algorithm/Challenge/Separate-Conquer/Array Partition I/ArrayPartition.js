
/**
 * @param {number[]} nums
 */
function sumMin(nums) {
    let result = 0
    let lo = 0, hi = nums.length - 1;
    for (let i = 0; i < nums.length / 2; i++) {
        result += Math.min(nums[lo + i], nums[hi - i])
    }
    return result;
}

/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function (nums) {
    const numsSort = nums.sort()
    return sumMin(numsSort)
};


let t = arrayPairSum([1, 4, 3, 2])
console.log(t)