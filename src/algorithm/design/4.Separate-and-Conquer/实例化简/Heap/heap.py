# 堆
class Heap:
    def __init__(self, data: list):
        self.data = data
        self._heapBottomUp()
    
    # heapBottomUp 自底向上构建最大堆
    def _heapBottomUp(self):
        for i in range(int(len(self.data)/2)-1, -1, -1):
            self._heapify(len(self.data), i)
    
    # n 为堆节点个数， root为小堆的根节点
    def _heapify(self, n: int, root: int):
        c1 = 2 * root + 1
        c2 = 2 * root + 2
        max = root
        # 将最大子节点与根节点做交换
        if c1 < n and self.data[c1] > self.data[max]:
            max = c1
        if c2 < n and self.data[c2] > self.data[max]:
            max = c2
        if max != root:
            self.data[max],self.data[root] = self.data[root],self.data[max]
            self._heapify(n, max)
        
