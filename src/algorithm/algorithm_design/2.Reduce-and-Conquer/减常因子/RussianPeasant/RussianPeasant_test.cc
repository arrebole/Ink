#include <stdio.h>
#include <stdlib.h>
#include "./RussianPeasant.cc"


void TestRussianPeasant(){
    if (RussianPeasant(4848, 2018)!= 9783264){
        exit(0);
    }
    printf("test PASS!\n");
}

int main(){
    TestRussianPeasant();
    return 0;
}