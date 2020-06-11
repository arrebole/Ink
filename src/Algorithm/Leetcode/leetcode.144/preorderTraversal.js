/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
function preorderTraversal(root) {
    const result = [];
    traversal(result, root);
    return result;
};

function traversal(out, root){
    if (root == null){
        return
    }
    out.push(root.val);
    traversal(out, root.left);
    traversal(out, root.right);
}