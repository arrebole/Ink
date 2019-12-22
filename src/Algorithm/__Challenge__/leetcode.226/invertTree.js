/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
function invertTree(root) {
    if(root == null) return null

    const r = invertTree(root.right);
    const l = invertTree(root.left);
    
    root.left = r;
    root.right = l;

    return root;
};