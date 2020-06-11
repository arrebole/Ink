

int min(int a, int b) { return a > b ? b : a; }

int surfaceArea(int** grid, int gridSize, int* gridColSize) {
  int result = 0;
  
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridColSize; j++) {
      // 垂直面积
      if (grid[i][j] > 0)      result += 4 * grid[i][j] + 2;
      // i 方向重叠面积, 减去最小重叠面积
      if (i < gridColSize - 1) result -= min(grid[i][j], grid[i][j + 1]) * 2;
      // j 方向重叠面积, 减去最小重叠面积
      if (j < gridSize - 1)    result -= min(grid[i][j], grid[i + 1][j]) * 2;
    }
  }

  return result;
}
