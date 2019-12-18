from addTwoNumbers import Solution, ListNode

# [2,4,3]
# [5,6,4]
S = Solution()

a = ListNode(2)
b = ListNode(4)
c = ListNode(3)
a.next = b
b.next = c

d = ListNode(5)
e = ListNode(6)
f = ListNode(4)
d.next = e
e.next = f

print(S.parse(S.addTwoNumbers(a, d), []))