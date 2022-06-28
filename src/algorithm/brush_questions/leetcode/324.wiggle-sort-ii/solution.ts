#! /usr/bin/env deno
// 324. 摆动排序 II @see https://leetcode.cn/problems/wiggle-sort-ii/


function wiggleSort(nums: number[]): void {
    const sortdNums = bucketSort(nums);
    const lo = sortdNums.slice(0, Math.ceil(sortdNums.length / 2))
    const hi = sortdNums.slice(lo.length, sortdNums.length)

    nums.length = 0;
    while (lo.length > 0 || hi.length > 0) {
        if (lo.length > 0) {
            nums.push(lo.pop()!);
        }
        if (hi.length > 0) {
            nums.push(hi.pop()!)
        }
    }
};


function bucketSort(nums: number[]) {
    const bucket = new Array();
    for (const num of nums) {
        if (typeof bucket[num] === 'undefined') {
            bucket[num] = 1;
        } else {
            bucket[num]++;
        }
    }
    const result: number[] = []
    for (let i = 0; i < bucket.length; i++) {
        while (bucket[i] && bucket[i]--) {
            result.push(i)
        }
    }
    return result;
}