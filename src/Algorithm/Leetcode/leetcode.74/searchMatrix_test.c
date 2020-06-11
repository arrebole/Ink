#include "./searchMatrix.c"
#include <stdio.h>

int main() {
  int m1[] = {1};
  int* matrix[] = {m1};
  int matrixColSize = 1;
  int r = searchMatrix(matrix, 1, &matrixColSize, 1);
  printf("%d", r);
  return 0;
}