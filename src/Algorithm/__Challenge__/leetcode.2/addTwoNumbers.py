
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def parse(self, node: ListNode, out: list) -> list:
        if node == None:
            return out
        out.append(node.val)
        return self.parse(node.next, out)    
    
    def createListNode(self, src: list)->ListNode:
        if src == None:
            return None

        queue = [ListNode(i) for i in src]
        for i in range(0, len(queue)-1):
            queue[i].next = queue[i+1]
        return queue[0]

    def add(self, a, b):
        result = []
        
        if len(a) > len(b):
            for i in range(len(a) - len(b)):
                b.append(0)
        elif len(a) < len(b):    
            for i in range(len(b) - len(a)):
                a.append(0)
        
        flag = 0
        for i in range(len(a)):
            t = a[i] + b[i] + flag
            flag = 0
            if t >= 10:
                flag+=1
                t-=10
            result.append(t)
        if flag != 0:
            result.append(flag)
        return result
    
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        numberSum = self.add(self.parse(l1, []), self.parse(l2, []))
        return self.createListNode(numberSum)