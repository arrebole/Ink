#! /usr/bin/env python
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(' ')
        if len(words) != len(pattern):
            return False

        pToS, sToP = dict(), dict()
        for i, v in enumerate(pattern):
            print(pToS, sToP)
            if not pToS.get(v):
                pToS.setdefault(v, words[i])
            if not sToP.get(words[i]):
                sToP.setdefault(words[i], v)
            if pToS[v] != words[i] or sToP[words[i]] != v:
                return False
        return True