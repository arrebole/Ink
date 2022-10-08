#! /usr/bin/env deno

// refer: https://leetcode-cn.com/problems/first-bad-version/

function mid(a : number, b: number){
    return Math.floor((a + b)/2) 
}

function solution (isBadVersion: any) {
    return function(n: number): number {
        let lo = 1, hi = n;
        while (lo < hi) {
            const midIsBadVersion = isBadVersion(mid(lo, hi));
            if (!midIsBadVersion && isBadVersion(mid(lo, hi) +1)) return mid(lo, hi) +1;
            else if (midIsBadVersion)                             hi = mid(lo, hi);
            else                                                  lo = mid(lo, hi);
        }
    };
};