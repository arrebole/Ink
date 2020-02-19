class QuickSelect:
    def lomutoPartition(self, a: list) -> int:
        p = a[0]
        s = 0
        for i in range(0, len(a)):
            if a[i] < p:
                s += 1
                a[s], a[i] = a[i], a[s]
        a[0], a[s] = a[s], a[0]
        return s

    def quickSelect(self, a: list, k: int):
        s = self.lomutoPartition(a)
        if s == (k - 1):
            return a[s]
        elif s > (k - 1):
            return self.quickSelect(a[:s], k)
        else:
            return self.quickSelect(a[s+1:], k-1-s)

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return QuickSelect().quickSelect(nums, len(nums)-k+1)