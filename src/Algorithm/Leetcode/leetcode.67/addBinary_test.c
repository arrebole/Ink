#include "addBinary.c"
#include <stdio.h>

void TestAddBinary(){
    char* s1 = "1010";
    char* s2 = "1011";
    printf("%s", addBinary(s1, s2));
}


int main(){
    TestAddBinary();
    return 0;
}