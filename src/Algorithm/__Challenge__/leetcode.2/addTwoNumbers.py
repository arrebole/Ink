
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def parse(self, node: ListNode) -> int:
        result = 0
        queue = list()
        while True:
            queue.append(node.val)
            if node.next == None:
                break
            node = node.next
        
        queue.reverse()
        for i in queue:
            result = result*10
            result += i

        return result    

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sum = self.parse(l1) + self.parse(l2)
        result = None
        local = result

        while sum > 0:
            if result == None:
                result = ListNode(sum%10)
                local = result
            else:
                local.next = ListNode(sum%10)
                local = local.next     
            sum = int(sum/10)
        
        if result == None:
            result = ListNode(0)
        return result