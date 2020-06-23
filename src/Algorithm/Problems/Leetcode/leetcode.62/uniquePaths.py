class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = self.dpInit(m, n)
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]

    def dpInit(self, m: int, n: int) -> list:
        dp = [[0]*n for i in range(m)]
        for i in range(m):
            dp[i][0] = 1
        for j in range(n):
            dp[0][j] = 1
        return dp