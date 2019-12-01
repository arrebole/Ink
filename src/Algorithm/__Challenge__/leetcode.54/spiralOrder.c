#include <stdlib.h>

// spiralOrder 螺旋矩阵
// \U0001f5e1减治法——减常数 逐层循环
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // 存放结果
    int* result = (int*)malloc(sizeof(int) * matrixSize * (*matrixColSize)); 
    int count = 0;

    int i1 = 0, i2 = matrixSize - 1;
    int j1 = 0, j2 = *matrixColSize - 1;
    
    while (j2 >= j1 && i2 >= i1){
        for(int j = j1; j <= j2; j++)       result[count++] = matrix[i1][j]; // 上边
        for(int i = i1 + 1; i <= i2; i++)   result[count++] = matrix[i][j2]; // 右边
        
        if(j2 <= j1 || i2 <= i1) break; 
        for(int j = j2 - 1; j > j1; j--)    result[count++] = matrix[i2][j]; // 下边
        for(int i = i2; i > i1; i--)        result[count++] = matrix[i][j1]; // 左边
        
        i1++; i2--; j1++; j2--;
    }
    
    *returnSize = count;
    return result;
}