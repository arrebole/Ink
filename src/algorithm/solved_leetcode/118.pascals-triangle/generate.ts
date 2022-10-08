#! /usr/bin/env deno

// refer: https://leetcode-cn.com/problems/pascals-triangle

// generate 生成杨辉三角形
function generate(numRows: number): number[][] {
    if (numRows == 0) return [];
    if (numRows == 1) return [[1]];
    const result = [[1], [1, 1]];
    for (let i = 2; i < numRows; i++){
        const row = [];
        for (let j = 1; j < result[i-1].length; j++) {
            row.push(result[i-1][j] + result[i-1][j-1]);
        }
        result.push([1, ...row, 1]);
    }
    return result;
};