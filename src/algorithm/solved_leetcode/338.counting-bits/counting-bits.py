# @see https://leetcode.cn/problems/counting-bits/?favorite=2cktkvj

from typing import List

class Solution:
    def countBit(self, n: int) -> int:
        result = 0
        while n > 0:
            if n & 0b1:
                result += 1
            n = n >> 1
        return result

    def countBits(self, n: int) -> List[int]:
        result = []
        for i in range(n + 1):
            result.append(self.countBit(i))
        return result