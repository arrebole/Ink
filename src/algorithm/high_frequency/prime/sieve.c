/* ----------------------------------------
 * 
 * 埃拉托斯特尼筛法 判断质数
 *
 * ---------------------------------------- */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// gen 创建大数组，将里面的数据填充为fill，返回的数组需要free()释放内存。
char* gen(int n, char fill) {
    char* result = (char*)malloc(n);
    for(int i = 0; i < n; i++){
        result[i] = fill;
    }
    return result;
}

// eratosthenes 将表中非质数置为0
char* eratosthenes(char* isPrimeTable, int len) {
    // 将0与1置为非质数
    isPrimeTable[0] = isPrimeTable[1] = 0;

    // 从筛选 2 ~ sqrt(len)
    int p = 2;
    while (p * p <= len) {
        if (isPrimeTable[p]) {
            for (int j = p * p; j <= len; j += p) {
                isPrimeTable[j] = 0;
            }
        }
        p++;
    }
    return isPrimeTable;
}

// isPrime 判断n是否为质数 
bool isPrime(int n) {
    assert(n >= 2);

    // 创建质数表
    char* isPrimeTable = eratosthenes(gen(n+1, 1), n);

    // 查询n是否为质数
    bool result = isPrimeTable[n] ? true : false;

    // 释放质数表
    free(isPrimeTable);
    return result;
}