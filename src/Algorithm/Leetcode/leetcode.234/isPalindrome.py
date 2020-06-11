class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        queue = self.listToArray(head)
        lo, hi = 0, len(queue)-1
        while lo < hi:
            if queue[lo] != queue[hi]:
                return False
            lo+=1
            hi-=1
        return True

    def listToArray(self, head: ListNode)->list:
        result = []
        while head != None:
            result.append(head.val)
            head = head.next
        return result