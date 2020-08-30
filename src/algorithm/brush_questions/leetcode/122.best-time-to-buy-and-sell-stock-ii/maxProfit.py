#! /usr/bin/env puthon

class Solution:
    # maxProfit 买股票的最佳时期， 贪心算法
    def maxProfit(self, prices: List[int]) -> int:
        result = 0
        for i in range(len(prices) - 1):
            if prices[i] < prices[i+1]:
                result+= prices[i+1] - prices[i]
        return result