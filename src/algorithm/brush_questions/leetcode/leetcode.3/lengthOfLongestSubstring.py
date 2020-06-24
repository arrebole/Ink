class Solution:
    # lengthOfLongestSubstring 无重复字符的最长子串
    def lengthOfLongestSubstring(self, s: str) -> int:
        result, lo, hi = 0, 0, 0
        seen = {}
        while hi < len(s):
            if(s[hi] in seen):
                result = max(result, hi-lo)
                lo,hi = seen[s[hi]] + 1, seen[s[hi]] + 1
                seen.clear()
            seen[s[hi]] = hi
            hi+=1
        return max(result, hi-lo)

Solution().lengthOfLongestSubstring("abcabcbb")