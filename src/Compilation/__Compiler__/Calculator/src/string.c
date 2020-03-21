#pragma one
#include "../include/string.h"
#include <stdlib.h>

// 字符串池
static char* pool = NULL;
static int ptr = 0;
static int capacity = 0;

void initPool(){
    capacity = 1024;
    pool = (char *)malloc(sizeof(char) * capacity);
}

void resize(){
    capacity*=2;
    pool = (char *)realloc(pool, sizeof(char) * capacity * 2);
}

// newString 创建一个字符串对象
char * newString(int size){
    if(pool == NULL) initPool();
    
    if(ptr + size>= capacity) resize();

    for(int i = ptr; i < ptr+size+1; i++) pool[i] = '\0';
    
    ptr+=(size+1);
    return &pool[ptr-size-1];
}

// freeString 释放所有字符串对象
void freeStrings(){
    if(pool == NULL) return;
    free(pool);
    pool = NULL;
}