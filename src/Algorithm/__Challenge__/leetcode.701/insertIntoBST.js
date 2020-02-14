function insertIntoBST(root, val) {
    if (root == null) return new TreeNode(val)
    insert(root, val)
    return root;    
};

function insert(root, val){
    if(val > root.val){
        if (root.right == null) root.right = new TreeNode(val);
        else insert(root.right, val);
    }

    if(val <= root.val){
        if(root.left == null) root.left = new TreeNode(val);
        else insert(root.left, val);
    }
}