//词法分析，字符流 -> 记号流
#pragma one
#include "../include/lex.h"
#include "../include/string.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// isOperators 判断字符是否是运算符
bool isOperators(char ch){
    if (ch == '+' || ch == '-') return true;
	return false;
}

// lexOperators 运算字符转换为记号
struct Token lexOperators(char ch){
    struct Token result;
    switch (ch){
    case '+':
        result.type = ADD;
        break;
    case '-':
        result.type = SUB;
        break;
    }
    result.value = NULL;
	return result;
}

// isInt 判断字符是否是整数
bool isInt(char ch){
    if (ch >= '0' && ch <= '9') return true;
	return false;
}

// lexInt 整形字符转换为记号
struct Token lexInt(char* ch, int size){
    struct Token result;
    result.type = INT;
    result.value = newString(size);
    for(int i = 0; i < size; i++) result.value[i] = ch[i];
    return result;
}

// TokenSteamInitCap 初始化容量
void TokenSteamInitCap(struct TokenSteam* tokenSteam){
    const int defaultCapacity = 6;
    tokenSteam->data = (struct Token *)calloc(defaultCapacity, sizeof(struct Token));
    tokenSteam->capacity = defaultCapacity;
}

// TokenSteamResize 扩容
void TokenSteamResize(struct TokenSteam* tokenSteam){
    struct Token* array = (struct Token *)calloc(tokenSteam->capacity *2, sizeof(struct Token));

    // 复制旧数据到新数组
    memcpy(array, tokenSteam->data, tokenSteam->size * sizeof(struct Token));
    
    // 释放旧内存
    free(tokenSteam->data);
    
    // 指针转移
    tokenSteam->data = array;
    tokenSteam->capacity = tokenSteam->capacity * 2;
}

// push 往记号流中添加标记
struct TokenSteam* push(struct TokenSteam* tokenSteam, struct Token token){

    if(tokenSteam->capacity == 0) TokenSteamInitCap(tokenSteam);
    if(tokenSteam->capacity <= tokenSteam->size) TokenSteamResize(tokenSteam);
    tokenSteam->data[tokenSteam->size++] = token;
    return tokenSteam;
}

// lex 词法分析；字符流 -> 记号流
struct TokenSteam lex(char* code, int len){
    struct TokenSteam result = {0, 0, NULL};
    for(int i = 0; i < len; i++){
        if(isOperators(code[i])) push(&result,lexOperators(code[i]));
        else if (isInt(code[i])){
            int intSize = 0;
            while (isInt(code[i+intSize])) intSize++;
            push(&result,lexInt(&code[i], intSize));
            i+=intSize;
        }
    }
    return result;
}