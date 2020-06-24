import { TreeNode, BSTtreeInsert, BSTtreeSearch } from "./BinarySearchTree"



function TestBSTtreeInsert() {
    const root = new TreeNode(10)
    BSTtreeInsert(root, new TreeNode(11))
    BSTtreeInsert(root, new TreeNode(1))
    BSTtreeInsert(root, new TreeNode(5))
    BSTtreeInsert(root, new TreeNode(16))

    if (root.Value != 10) {
        console.log("test Fail1")
        return
    }

    if (root.Right.Value != 11) {
        console.log("test Fail2")
        return
    }
    if (root.Left.Value != 1) {
        console.log("test Fail3")
        return
    }
    if (root.Left.Right.Value != 5) {
        console.log("test Fail4")
        return
    }
    if (root.Right.Right.Value != 16) {
        console.log("test Fail5")
        return
    }
    console.log("test PASS")
}




TestBSTtreeInsert()