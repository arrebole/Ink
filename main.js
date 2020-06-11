


function diameterOfBinaryTree(root) {
    if (root == null) return 0;
    return Math.max(
        maxDeep(root.left) + maxDeep(root.right),
        diameterOfBinaryTree(root.right),
        diameterOfBinaryTree(root.left)
    );
}

function maxDeep(root) {
    if (root == null) return 0;
    return Math.max(maxDeep(root.left), maxDeep(root.right)) + 1;
}