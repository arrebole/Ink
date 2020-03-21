#include "string.c"
#include <stdio.h>
#include <assert.h>

int main(){
    char* str1 = newString(5);
    char* str2 = newString(6);
    
    for(int i = 0; i <5; i++) str1[i] = '1';
    for(int i = 0; i <6; i++) str2[i] = '2';

    assert(str1[5] == '\0');
    
    return 0;
}