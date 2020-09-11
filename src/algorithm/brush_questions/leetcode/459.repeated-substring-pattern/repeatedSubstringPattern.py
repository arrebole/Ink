
def isSubstring(subStr: str, source: str)-> bool:
    if len(source) % len(subStr) != 0:
        return False
    return subStr * int(len(source) / len(subStr)) == source

class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for i in range(1, int(len(s) / 2) + 1):
            if isSubstring(s[:i], s):
                return True
        return False