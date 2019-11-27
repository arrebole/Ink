#include <stdbool.h>

void setZeroes(int** matrix, int martixSize, int* matrixColSize) {
  // 特殊点[0][0]标记
  bool isSet = false;
  // 标记
  for (int i = 0; i < martixSize; i++) {
    if (matrix[i][0] == 0) isSet = true;

    for (int j = 0; j < *matrixColSize; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  // [i][0] && [0][j] 都标记的行列值为零
  for (int i = 1; i < martixSize; i++) {
    for (int j = 0; j < *matrixColSize; j++) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  // 制零第一个特殊点
  if (matrix[0][0] == 0) {
    for (int i = 0; i < *matrixColSize; i++) matrix[0][i] = 0;
  }
  if (isSet) {
    for (int i = 0; i < martixSize; i++) {
      matrix[i][0] = 0;
    }
  }
}