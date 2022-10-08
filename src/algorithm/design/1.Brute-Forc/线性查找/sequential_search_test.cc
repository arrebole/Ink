#include <stdio.h>
#include <stdlib.h>
#include "./sequential_search.cc"

int main(){

    int data[] = {4,5,6,1,2,8,0,3,5,34,53,75,13,64,98,67};
    int eqIndex = SequentialSearch(data, sizeof(data)/sizeof(int), 13);

    if (eqIndex != 12 ){
        printf("[test fail]\n");
        exit(0);
    } 

    printf("[test PASS] OK\n");
    return 0;
}