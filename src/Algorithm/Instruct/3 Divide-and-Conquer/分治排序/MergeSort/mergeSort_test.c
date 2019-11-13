#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./mergeSort.c"

void TestMergeSort(){
    int data[200];
    srand(time(NULL));
    for(int i = 0; i < 200; i++) {
        data[i] = rand();
    }
    
    mergeSort(data, 0, 200);

    for(int i = 0; i < 199; i++){
        if(data[i] > data[i+1]){
            printf("test Fail\n");
            exit(0);
        }
    }
    printf("test PASS\n");
}

int main(){
    TestMergeSort();
    return 0;
}