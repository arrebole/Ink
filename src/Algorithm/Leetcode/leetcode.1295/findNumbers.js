/**
 * @param {number[]} nums
 * @return {number}
 */

const reducer = (accumulator, currentValue) => {
    if(currentValue.toString().length % 2 == 0) return accumulator + 1;
    return accumulator;
}

function findNumbers(nums) {
    return nums.reduce(reducer, 0);
};

