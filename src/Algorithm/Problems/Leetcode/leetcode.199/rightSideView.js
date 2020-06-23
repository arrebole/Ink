/* Definition for a binary tree node.
* function TreeNode(val) {
*     this.val = val;
*     this.left = this.right = null;
* }
*/
/**
 * rightSideView 二叉树的右视图
 * exploit 暴力法-bfs
* @param {TreeNode} root
* @return {number[]}
*/
function rightSideView(root) {
    const result = []
    if(root == null) return result
    
    let queue = [root]
    while(queue.length > 0){
        const row = []
        result.push(queue[queue.length].val)
        for(let el of queue){
            if (el.left != null) row.push(el.left)
            if (el.right != null) row.push(el.right)
        }
        queue = row
    }
    return result
};