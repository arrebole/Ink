#! /usr/bin/env python

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def __init__(self) -> None:
        self.res = []

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        self.dfs(root, targetSum, [])
        return self.res

    def dfs(self, root: Optional[TreeNode], targetSum: int, path: List[int]):
        if root == None:
            return

        path.append(root.val)
        if root.left == None and root.right == None and targetSum == root.val:
            self.res.append(path.copy())

        self.dfs(root.left, targetSum - root.val, path)
        self.dfs(root.right, targetSum - root.val, path)
        path.pop()