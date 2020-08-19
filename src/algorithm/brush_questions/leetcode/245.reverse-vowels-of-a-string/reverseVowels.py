vowel = set("aeiouAEIOU")

def isVowel(char: str)-> bool:
    return char in vowel

def getVowelsList(s):
    result = []
    for i, char in enumerate(s):
        if isVowel(char):
            result.append(i)
    return result

class Solution(object):
    def reverseVowels(self, s):
        result = list(s)
        revers = getVowelsList(s)
        lo, hi = 0, len(revers) -1
        while lo < hi:
            result[revers[lo]],result[revers[hi]] = result[revers[hi]], result[revers[lo]]
            lo += 1
            hi -= 1
        return ''.join(result)




