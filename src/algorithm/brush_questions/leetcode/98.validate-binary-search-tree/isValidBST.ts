// problems: https://leetcode-cn.com/problems/validate-binary-search-tree

interface TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
}

// inOrderTraversal 对二叉树进行中序遍历，将结果存储到 result 中
function inOrderTraversal(root: TreeNode | null, result: number[]) {
    if (root == null) return;
    inOrderTraversal(root.left, result);
    result.push(root.val);
    inOrderTraversal(root.right, result);
}

// isValidBST 验证二叉树是否为二叉搜索树 [变治法/问题化简、分治法/中序遍历、T(n)=O(2n)]
// 通过判断中序遍历的结果是否是升序来确定是否为二叉搜索树。
function isValidBST(root: TreeNode | null): boolean {
    const inOrderResult = [];
    inOrderTraversal(root, inOrderResult);
    for (let i = 1; i < inOrderResult.length; i++) {
        if (inOrderResult[i] < inOrderResult[i - 1]) return false;
    }
    return true;
};

