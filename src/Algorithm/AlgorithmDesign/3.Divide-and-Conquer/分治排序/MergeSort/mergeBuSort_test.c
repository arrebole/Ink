#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "./mergeBuSort.c"

void TestMergeBuSort(){
    int data[200];
    srand(time(NULL));
    for(int i = 0; i < 200; i++) {
        data[i] = rand();
    }
    
    mergeBuSort(data, 200);

    for(int i = 0; i < 199; i++){
        if(data[i] > data[i+1]){
            printf("test Fail\n");
            exit(0);
        }
    }
    printf("test PASS\n");
}

int main(){
    TestMergeBuSort();
    return 0;
}