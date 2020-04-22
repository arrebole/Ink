#include <stdio.h>
#include <stdlib.h>
#include "./bruteForceStringMatch.cc"

int main(){

    char data[] = "sdgqvwbelqh;qdnqhdihdwmd2nxjqwyeywqge1297eoqihvdol";
    char pattern[] = "dol";
    // 由于char 字符串末尾会添加'\0',所以需要-1
    int eqIndex = BruteForceStringMatch(data, sizeof(data)/sizeof(char) -1, pattern, sizeof(pattern)/sizeof(char)-1);

    if (eqIndex != 47 ){
        printf("[test fail] %d %d\n", eqIndex, sizeof(data)/sizeof(char));
        exit(0);
    } 

    printf("[test PASS] OK\n");
    return 0;
}