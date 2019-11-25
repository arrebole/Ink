#include <stdlib.h>
#include <stdbool.h>

// 判断int的长度
int LenInt(int x){
    int result = 0;
    while (x != 0){
        x = x / 10;
        result++;
    }
    return result;
}

// 将int转换成array
int* intToArray(int x, int len){
    int* result = (int*)malloc(sizeof(int) * len);
    for(int i = 0; i < len; i++){
        result[i] = x%10;
        x/=10;
    }
    return result;
}

// isPalindrome 判断回文数
// C(n) = 1/2n ∈ Ω(n)
bool isPalindrome(int x){
    
    int len = LenInt(x);
    // 负数不是回文数 单数字必定是回文数
    if (x < 0) return false;
    if (len == 1) return true;    
    
    int * array = intToArray(x, len);
 
    // 双指针技巧
    int lo = 0, hi = len-1;
    while(lo < hi){
        if (array[lo++] != array[hi--]) return false;
    }
    return true;
}