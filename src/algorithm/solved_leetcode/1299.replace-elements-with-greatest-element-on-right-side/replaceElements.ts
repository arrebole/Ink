// refer: https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side

function findMax(nums: number[]) {
    if (nums.length <= 0) return -1;
    return nums.reduce((p, v) => v > p ? v : p, nums[0]);
}

// replaceElements 将每个元素替换为右侧最大元素
function replaceElements(arr: number[]): number[] {
    return arr.map((v, i)=> findMax(arr.slice(i+1)));
};