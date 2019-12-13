/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let l = 0, r = 0, result = 0;
    for(l = 0; l < nums.length; l+=r+1, r=0){
        if(nums[l] == 1){
            while(nums[l+r] == 1) r++;
            result = r > result?r:result;
        }
    }
    return result;
};