#include <stdio.h>
#include <stdlib.h>
#include "./binarySearch.cc"


void TestBinarySaerch(){
    int data[] = {1,2,4,6,9,12,17,20,23,28,30,39,41,44,47,55,59};
    if (binarySearch(data, sizeof(data)/sizeof(int), 41) != 12){
        printf("test fail!\n");
        exit(0);
    }
    printf("test PASS\n");
}


int main(){
    TestBinarySaerch();
    return 0;
}