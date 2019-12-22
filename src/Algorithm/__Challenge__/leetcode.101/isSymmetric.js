/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
function isSymmetric(root) {
    if(root == null) return true
    return isEq(root.left, root.right);
};

function isEq(l, r){
    if(l == null && r == null) return true
    if(r == null || l == null) return false
    return (l.val == r.val) && isEq(l.left, r.right) && isEq(l.right, r.left);
}