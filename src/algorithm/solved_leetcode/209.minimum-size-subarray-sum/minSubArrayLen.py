from typing import List

class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        result, sum, left = 0, 0, 0
        for right in range(len(nums)):
            sum += nums[right]
            while sum >= s:
                if result == 0:
                    result = right - left + 1
                else:
                    result = min(result, right - left + 1)
                sum -= nums[left]
                left += 1
        return result

print(Solution().minSubArrayLen(4, [1,4, 4]))
