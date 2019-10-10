#include <stdio.h>
#include <stdlib.h>
#include "interpolationSearch.cc"


void TestInterpolationSearch(){
    int a[] = {1, 3, 5, 7, 8, 10, 13, 16, 18, 20, 23, 26, 28, 30, 32, 25, 37, 40};
    if (interpolationSearch(a, 18, 20) != 9){
        printf("test Fail\n");
        exit(0);
    }
    printf("test PASS!\n");
}


int main(){
    TestInterpolationSearch();
    return 0;
}