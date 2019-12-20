/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * maxDepth 求二叉树的深度
 * 贪心算法 max(tree.left, tree.right)
 * @param {TreeNode} root
 * @return {number}
 */
function maxDepth(root) {
    if(root == null) return 0;
    return max(maxDepth(root.left), maxDepth(root.right)) + 1;
};

function max(a,b){
    return a>b?a:b;
}