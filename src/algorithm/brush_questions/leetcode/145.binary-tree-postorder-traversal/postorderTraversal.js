function postorderTraversal(root) {
    const result = [];
    traversal(result, root);
    return result; 
};

function traversal(out, root){
    if (root == null){
        return
    }
    traversal(out, root.left);
    traversal(out, root.right);
    out.push(root.val);
}