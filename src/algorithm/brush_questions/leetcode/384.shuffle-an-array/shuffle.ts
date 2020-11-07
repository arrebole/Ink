#! /usr/bin/env deno

// refer: https://leetcode-cn.com/problems/shuffle-an-array/

class Solution {
    constructor(nums: number[]) {
        this.original = Array.from(nums);
        this.active = nums;
    }

    private original: number[];
    private active: number[];

    private randomIndex(){
        return Math.round(Math.random() * (this.original.length -1));
    }

    reset(): number[] {
        return this.original;
    }

    // shuffle 洗牌算法打乱数组
    shuffle(): number[] {
        const i = this.randomIndex();
        const element = this.active[i];
        this.active.splice(i, 1);
        this.active.push(element);
        return this.active;
    }
}
