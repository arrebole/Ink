

#include <assert.h>
#include <math.h>
#include "mySqrt.c"
#include <stdio.h>

void TestMySqrt(int p, int a){
    assert(mySqrt(p) == a);
}

int main(){
    for(int i = 0;i < 100; i++){
        TestMySqrt(i,(int)sqrt(i));
    }
    return 0;
}