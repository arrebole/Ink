/**
 * isPossibleDivide 划分数组为连续数字的集合
 * 🗡排序问题
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
function isPossibleDivide(nums, k) {
    if(nums.length < k || nums.length %k != 0) return false
    nums = nums.sort((a,b)=> a-b);
    const len = nums.length/k
    for(let i = 0; i< len; i++){
        nums =  possible(nums, k);
        if(nums == null) return false;
    }
    return true;
};

/**
 * 
 * @param {number[]} nums 
 * @param {*} k 
 */
function possible(nums, k){
    const queue = [nums.shift()]
    while(queue.length != k){
        let flage = true
        for(let i = 0; i < nums.length; i++){
            if(nums[i] -  queue[queue.length-1] == 1){
                queue.push(nums[i]);
                nums.splice(i, 1)
                flage = false;
                break;
            }
        }
        if( flage ) return null;
    }
    return nums
}