/**
 * @param {number[]} nums
 * @return {number}
 */
function removeDuplicates(nums) {
    if(nums.length == 1) return 1;

    for(let i = 1; i < nums.length; i++){
        if(nums[i] == nums[i-1]){
            let hi = i;
            while (nums[hi] == nums[i] && hi < nums.length - 1) hi++;
            for(let j = i; j < hi; j++) nums[j] = nums[hi];
        }
    }
    return countDuplicates(nums);
};

function countDuplicates(nums){
    let count = 1;
    for(let i = 1; i< nums.length; i++){
        if(nums[i] != nums[i-1]) count++
    }
    return count;
}
console.log(removeDuplicates([1,1,2]))