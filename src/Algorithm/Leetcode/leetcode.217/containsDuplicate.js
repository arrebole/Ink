/**
 * containsDuplicate 给定一个整数数组，判断是否存在重复元素。
 * @param {number[]} nums
 * @return {boolean}
 */
function containsDuplicate(nums) {
    const seen = new Set()
    for(const i of nums){
        if(seen.has(i)) return true;
        seen.add(i)
    }
    return false;
};

module.exports = containsDuplicate