
// arrayPairSum 数组切分贪心算法
var arrayPairSum = function(nums) {
    let result = 0;
    nums = nums.sort((a, b)=> a-b);
    for(let i = 0; i < nums.length; i+=2){
        result += nums[i];
    }
    return result;
};
