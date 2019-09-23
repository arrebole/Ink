#include <stdio.h>
#include <stdlib.h>
#include "./bubble_sort.cc"

int main(){

    int data[] = {4,5,6,1,2,8,0,3,5,34,53,75,13,64,98,67};
    bubble_sort(data, sizeof(data)/sizeof(int));

    for(int i=0 ; i < sizeof(data)/sizeof(int) - 1; i++){
        if (data[i] > data[i+1]) {
            printf("[test fail]\n");
            exit(0);
        }
    }
    printf("[test PASS]\n");
    return 0;
}