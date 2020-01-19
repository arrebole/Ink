from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        obstacleGrid = self.reObstacles(obstacleGrid)
        obstacleGrid = self.makeDp(obstacleGrid)

        for i in range(1, len(obstacleGrid)):
            for j in range(1, len(obstacleGrid[0])):
                if obstacleGrid[i][j] == float("inf"):
                    obstacleGrid[i][j] = 0
                else:
                    if obstacleGrid[i-1][j] == float("inf"):
                        obstacleGrid[i-1][j] = 0
                    if obstacleGrid[i][j-1] == float("inf"):
                        obstacleGrid[i][j-1] = 0
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
        return 0 if obstacleGrid[-1][-1] == float("inf") else obstacleGrid[-1][-1]

    def reObstacles(self, obstacleGrid: List[List[int]]):
        for i in range(len(obstacleGrid)):
            for j in range(len(obstacleGrid[0])):
                if (obstacleGrid[i][j] != 0):
                    obstacleGrid[i][j] = float("inf")
        return obstacleGrid
    
    def makeDp(self, obstacleGrid: List[List[int]]):
        for i in range(len(obstacleGrid)):
            if obstacleGrid[i][0] == float("inf"):
                break
            obstacleGrid[i][0] = 1
        for j in range(len(obstacleGrid[0])):
            if obstacleGrid[0][j] == float("inf"):
                break
            obstacleGrid[0][j] = 1
        return obstacleGrid