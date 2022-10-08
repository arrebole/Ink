#! /usr/bin/env python

from typing import List
 
class Solution:
    def horizontalReversal(self, A: List[List[int]]):
        for row in A:
            row.reverse()
        return A

    def bitReverse(self, A: List[List[int]]):
        for i in range(len(A)):
            for j in range(len(A[i])):
                A[i][j] = 1 if A[i][j] == 0 else 0 
        return A

    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        return self.bitReverse(self.horizontalReversal(A))