

function findDisappearedNumbers(nums: number[]): number[] {
    const aux = new Array(nums.length).fill(-1);
    for (let i = 0; i < nums.length; i++) {
        aux[nums[i]] = nums[i];
    }
    const result = [];
    for (let i = 1; i < aux.length; i++){
        if (aux[i] != i) result.push(i);
    }
    return result;
};