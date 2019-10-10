export class TreeNode{
    constructor(v: number){
        this.Value = v
        this.Parent = null
        this.Left = null
        this.Right = null
    }

    Value: number
    Parent: TreeNode 
    Left: TreeNode
    Right: TreeNode
}

// BSTtreeInsert 二叉查找树的插入(非递归版本)
export function BSTtreeInsert(root: TreeNode, node: TreeNode){
    let local = root;
    while(true){
        if(local.Left == null && node.Value <= local.Value) {
            local.Left = node;
            return;
        }
        if (local.Right == null && node.Value > local.Value ) {
            local.Right = node;
            return;
        }

        if(local.Left != null && node.Value <= local.Value ){
            local = local.Left;
            continue;
        }

        if(local.Right != null && node.Value > local.Value){
            local = local.Right;
            continue;
        } 
    }
}

// BSTtreeInsert 二叉查找树的插入(递归版本)
export function BSTtreeSearch(root: TreeNode, key: number){
    if (root.Value == key) return true
    
    if( root.Left != null && key <= root.Value)         return BSTtreeSearch(root.Left, key)
    else if( root.Right != null && key > root.Value)    return BSTtreeSearch(root.Right, key)
    else                                                return false
}