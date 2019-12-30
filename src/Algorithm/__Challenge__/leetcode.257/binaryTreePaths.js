/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string[]}
 */
function binaryTreePaths(root) {
    const result = []
    dfs(root, "", result);
    return result;
};

function dfs(root, path, paths){
    if(root == null) return
    path+=`${root.val}`
    
    if(root.left == null && root.right == null) {
        paths.push(path)
    }
    else{
        path+="->"
        dfs(root.left, path, paths)
        dfs(root.right, path, paths)
    }
}