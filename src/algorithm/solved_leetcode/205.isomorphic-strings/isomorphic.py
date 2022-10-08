#! /usr/bin/env python

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if (len(s) != len(t)):
            return False
        
        strmap1, strmap2 = dict(), dict()
        for i in range(len(s)):
            if s[i] not in strmap1 and t[i] not in strmap2:
                strmap1[s[i]] = t[i]
                strmap2[t[i]] = s[i]
            else:
                if strmap1.get(s[i]) == t[i] and strmap2.get(t[i]) == s[i]:
                    continue
                else:
                    return False
        return True