#include <stdbool.h>
#include <stdio.h>

// Coordinate 表示二维数组坐标的结构体
struct Coordinate{
  int row;
  int col;
};

// 将一维数组的索引 转换为二维数组的索引
struct Coordinate transform(int matrixColSize, int index) {
  struct Coordinate result = {
    row : index % matrixColSize,
    col : index / matrixColSize,
  };
  return result;
}

// searchMatrix 搜索二维矩阵
// 减治法—二分查找
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
  
  if ( matrixSize == 0 || *matrixColSize == 0) return false;
  int len = matrixSize * (*matrixColSize) - 1;
  int lo = 0, hi = len, mid;
  
  while (lo <= hi){
        mid = (lo+hi)/2;
        if( mid*2 < hi) mid++;
        struct Coordinate p = transform(*matrixColSize, mid);
        if (matrix[p.col][p.row] == target) return true;
        if (matrix[p.col][p.row] > target) hi = mid - 1; 
        if (matrix[p.col][p.row] < target) lo = mid + 1;   
  }
  return false;
}