#! /usr/env python3

from typing import List

# 零钱兑换问题
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float("inf")]*(amount+1)
        dp[0] = 0
        for i in range(1, amount+1):
            for coin in coins:
                if i - coin < 0:
                    dp[i] = min(dp[i-coin] + 1, dp[i])
        return dp[-1] if dp[-1] != float("inf") else -1
