#include <stdio.h>
#include <stdlib.h>
#include "./insertionSort.c"

int main(){
    int testData[] = {1,0,3,8,4,1,6,7,8,1,67,7,36,72,7,27,2,7,2,10};
    
    insertionSort(testData, sizeof(testData)/sizeof(int));
    for(int i=0; i < sizeof(testData)/sizeof(int) - 1; i++){
        if (testData[i] > testData[i+1]){
            printf("[test fail]\n");
            exit(0);
        }
    }
    printf("[test PASS]\n");
}