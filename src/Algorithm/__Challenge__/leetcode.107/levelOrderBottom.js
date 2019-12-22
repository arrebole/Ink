/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
function levelOrderBottom(root) {
    const result = []
    
    const queue = [[root]]
    while( queue.length > 0 ){
        let items = queue.shift()
        result.push(items.map(i=>i.val))
        
        let next = [];
        for(let i of items){
            if (i.left != null)   next.push(i.left);
            if (i.right != null)  next.push(i.right);
        }
        if(next.length != 0)      queue.push(next);
    }
    return result.reverse();
};