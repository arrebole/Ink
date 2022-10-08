from isomorphic import Solution

def testIsomorphic():
    assert Solution().isIsomorphic("egg", 'add') == True
    assert Solution().isIsomorphic("foot", 'bar') == False
    assert Solution().isIsomorphic("paper", "title") == True
    assert Solution().isIsomorphic("badc", "baba") == True

if __name__ == '__main__':
    testIsomorphic()