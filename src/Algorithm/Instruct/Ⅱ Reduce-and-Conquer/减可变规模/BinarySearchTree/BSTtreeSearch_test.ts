import {TreeNode, BSTtreeSearch, BSTtreeInsert} from "./BinarySearchTree"

function TestBSTtreeSearch() {
    const root = new TreeNode(10)
    BSTtreeInsert(root, new TreeNode(11))
    BSTtreeInsert(root, new TreeNode(1))
    BSTtreeInsert(root, new TreeNode(5))
    BSTtreeInsert(root, new TreeNode(16))
    
    if (!BSTtreeSearch(root, 5)) {
        console.log("test Fail1")
        return
    }

    if (BSTtreeSearch(root, 9)) {
        console.log("test Fail2")
        return
    }
    console.log("test PASS")
}
TestBSTtreeSearch()