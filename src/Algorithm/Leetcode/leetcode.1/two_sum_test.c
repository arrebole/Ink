#include <stdio.h>
#include "./two_sum.c"

int main(){
    int nums[] = {2,7,11,15};
    int returnSize;
    int* r = twoSum(nums, 4, 9, &returnSize);
    printf("%d %d",r[0], r[1]);
    return 0;
}