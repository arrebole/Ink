#include <stdlib.h>

int* aux = NULL;

void Merge(int array[], int left, int m, int right) {
  int i, j, k;
  for (i = left, j = m + 1, k = 0; k <= right - left; k++) {
    if (i == m + 1) {
      aux[k] = array[j++];
      continue;
    }
    if (j == right + 1) {
      aux[k] = array[i++];
      continue;
    }

    if (array[i] < array[j]) aux[k] = array[i++];
    else                     aux[k] = array[j++];
  }

  for (i = left, j = 0; i <= right; i++, j++) array[i] = aux[j];
}

// 归并排序
void MergeSort(int* array, int start, int end) {
  if (start < end) {
    int i = (end + start) / 2;
    MergeSort(array, start, i);
    MergeSort(array, i + 1, end);
    Merge(array, start, i, end);
  }
}

// maximumGap 相邻最大距离
int maximumGap(int* nums, int numsSize) {
  if (numsSize < 2) return 0;

  aux = (int*)malloc(sizeof(int) * numsSize);
  MergeSort(nums, 0, numsSize - 1);

  int result = 0;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] - nums[i - 1] > result) {
      result = nums[i] - nums[i - 1];
    }
  }
  return result;
}