class Solution:
    def reverseList(self, head):
        p, rev = head, None
        while p:
            rev, rev.next, p = p, rev, p.next
        return rev