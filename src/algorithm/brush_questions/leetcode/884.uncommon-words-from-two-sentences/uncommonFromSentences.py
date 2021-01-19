#! /usr/bin/env python
from typing import List

class Solution:
    def uniqueStr(self, a: List[str]):
        seen =  dict()
        for s in a:
            if s in seen:
                seen[s] += 1
            else:
                seen[s] = 0
        result = []
        for s in seen:
            if seen[s] == 0:
                result.append(s)
        return result

    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        return self.uniqueStr(A.split(' ') + B.split(' '))
