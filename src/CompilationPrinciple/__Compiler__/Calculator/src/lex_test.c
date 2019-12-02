#include "lex.c"
#include <string.h>
#include <stdio.h>

int main(){
    char* data = "1 + 22 - 15 + 7  + 123";
    struct TokenSteam ts =  lex(data, strlen(data));

    for(int i = 0; i < ts.size; i++){
        printf("(%d) \n", ts.data[i].type);   
    }
    return 0;
}