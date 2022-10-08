#! /usr/bin/env python

from typing import List

def countNumber(nums: List[int]):
    result = dict()
    for i in nums:
        if i not in result:
            result[i] = 0
        result[i] = result[i] + 1
    return result

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        result = 0
        for value in countNumber(nums).values():
            result += self.combination(value)
        return result

    def combination(self, n: int) -> int:
        return int(n * (n - 1) / 2)