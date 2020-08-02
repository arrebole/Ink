// 求两数之和
#include <stdlib.h>

int* createResult(int a, int b, int* returnSize){
    int* result = (int*)malloc(sizeof(int)*2);
    result[0] = a;
    result[1] = b;
    *returnSize = 2;
    return result;
}

// twoSum
// 暴力法
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int hi = numsSize - 1;

    for(int i = hi; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if (nums[i] + nums[j] == target) {
                return createResult(j, i, returnSize);
            }
        }
    }
    return 0;
}

