#! /usr/env python3

from typing import List

class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        count, IsPrime = 0, self.eratosthenes(n)
        for i in range(2, n):
            if IsPrime[i]:
                count+=1
        return count
    
    def eratosthenes(self, n:int) -> List[bool]:
        IsPrime = [True] * (n + 1)
        for i in range(2, int(n ** 0.5) + 1):
            if IsPrime[i]:
                for j in range(i * i, n + 1, i):
                    IsPrime[j] = False
        return IsPrime