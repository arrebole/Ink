#! /usr/env deno
/**
 * 515. 在每个树行中找最大值
 * @see https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
 */


/**
 * Definition for a binary tree node.
 */
class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}


export function largestValues(root: TreeNode | null): number[] {
    const result: number[] = []
    bfs(root, (num) => result.push(Math.max(...num)))
    return result;
};

function bfs(root: TreeNode | null, handle: (nums: number[]) => any) {
    if (root === null) {
        return;
    }
    let queue = new Array<TreeNode>(root);
    let nextQueue = new Array<TreeNode>()
    while (queue.length > 0) {
        handle(queue.map(v => v.val));
        for (const node of queue) {
            if (node.left) nextQueue.push(node.left);
            if (node.right) nextQueue.push(node.right);
        }
        queue = nextQueue;
        nextQueue = [];
    }
}