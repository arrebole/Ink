#! /usr/bin/env python
from typing import List

class Solution(object):
    def nextPermutation(self, nums):
        return self.lexicographicPermute(nums)

    def lexicographicPermute(self, array: List):
        i = self.findMaxOrdered(array)
        if i == -1:
            array.sort()
            return array

        j = self.findMaxBigIndex(array, array[i])
        array[i], array[j] = array[j], array[i]
        return self.recover(array, i+1, len(array)-1)
    
    # findMaxBigIndex 找到比n大的数的最大索引
    def findMaxBigIndex(self, array: List[int], n: int):
        result = -1
        for i, v in enumerate(array):
            if v > n:
                result = i
        return result

    # findMaxOrdered 寻找数组中最大升序
    def findMaxOrdered(self, array: List[int]):
        result = -1
        for i in range(0, len(array)-1):
            if array[i+1] > array[i]:
                result = i
        return result

    def recover(self, array: List[int], lo: int, hi: int):
        while lo < hi:
            array[lo], array[hi] = array[hi], array[lo]
            lo += 1
            hi -= 1
        return array

if __name__ == '__main__':
    print(
        Solution().nextPermutation([3, 2, 1])
    )