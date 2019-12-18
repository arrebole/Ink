from typing import List

class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        result = 0
        if len(nums) == 0:
            return result
        
        sum = 0
        nums = nums.sort(reverse=True)
        for i in nums:
            if sum > s:
                return result - 1
            elif sum == s:
                return result
            sum+=i
            result+=1
        return result

Solution().minSubArrayLen(4, [1,4,4])
