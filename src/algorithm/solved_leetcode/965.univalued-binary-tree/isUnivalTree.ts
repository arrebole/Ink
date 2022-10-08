
// TreeNode Definition for a binary tree node.
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

// isUnivalTree 判断二叉树中每个结点的值是否相等
// 深度优先搜索，判断左右节点是否与根节点一致
function isUnivalTree(root: TreeNode | null): boolean {
    if (root == null){
        return true
    }

    if (root.right && root.val != root.right.val) return false;
    if (root.left && root.val != root.left.val) return false;

    return isUnivalTree(root.left) && isUnivalTree(root.right);
};
