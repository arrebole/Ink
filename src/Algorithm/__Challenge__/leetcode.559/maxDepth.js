/*---------------------------------------------------------------------------------------------
 *  create at: 2020-05-30
 *  Author: <concurrent.exec@gmail.com>
 *--------------------------------------------------------------------------------------------*/


/**
 * @param {Node} root
 * @return {number}
 */
function maxDepth(root) {
    if (root == null) return 0;
    return dfs(root, 1);
};

/**
 * @param {Node} node 
 * @param {number} depth 
 */
function dfs(node, depth){
    if (node.children.length == 0) return depth;

    const results = []
    for(const item of node.children){
        results.push(dfs(item, depth+1));
    }
    return Math.max(...results);
}