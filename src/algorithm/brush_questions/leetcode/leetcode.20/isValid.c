#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* Stack(int len){
    char* result = (char*)malloc(sizeof(char) * len);
    return result;
}

// isValid 判断有效的括号
bool isValid(char* s){
    int len = (int)strlen(s);
    
    // 只有偶数长度才有可能
    if (len % 2 != 0) return false;
   
    char* stack = Stack(len);
    int count = 0;
    
    // 入栈 
    for(int i = 0; i < len; i++){
        // 将（[{ 入栈
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[count++] = s[i];
            continue;
        }
       
        if(count <= 0) return false;

        // 出栈
        char top = stack[--count];
        if((s[i] == ')' && top != '(')
            || (s[i] == ']' && top != '[')
            || (s[i] == '}' && top != '{')
        
        ) return false;
        
    }

    // 还有剩余（[{ 未匹配
    if (count != 0){
        return false;
    }
    return true;
}