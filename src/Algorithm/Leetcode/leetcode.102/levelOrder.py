# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        result = []
        queue = [[root]]
        while len(queue) > 0:
            next = []
            group = []
            for i in queue.pop(0):
                if i == None:
                    continue
                group.append(i.val)
                next.append(i.left)
                next.append(i.right)
            if len(next) > 0:
                queue.append(next)
                result.append(group)
        return result