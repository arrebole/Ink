#include <stdio.h>
#include <stdlib.h>
#include "./shellSort.c"

int main(){
    int testData[] = {1,3,0,32,5,46,2,5,6,7,5,47,1,6,57,54,7,8,14,64,7,2,7,9};
    shellSort(testData, sizeof(testData)/sizeof(int));

    for(int i = 0; i < sizeof(testData)/sizeof(int); i++){
        if (testData[i] > testData[i+1]){
            printf("[test fail]\n");
            exit(0);
        }
    }
    printf("[test PASS]");
    return 0;
}