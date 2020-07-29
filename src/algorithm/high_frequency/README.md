# High frequency algorithm

高频出现的必备基础算法

## Table of Contents
+ [质数](#质数)
    + [试除法](#试除法)
    + [埃拉托斯特尼筛法](#埃拉托斯特尼筛法)

## 质数
判断质数（素数）是高频出现的算法，素数指在大于1的自然数中，除了1和该数自身外，无法被其他自然数整除的数。

### 试除法
> 最直接的暴力算法，Time complexity: O(sqrt(n))

穷举试除判断是否能够被整除，由于最小质因数肯定小于等于他的平方根，所以试除区间可以取[2，sqrt(n)-1]。

```c
bool isPrime(int n) {
    assert(n >= 2);
    int lo = 1, hi = sqrt(n);
    while(++lo <= hi) {
        if (n % lo == 0) return false;
    }
    return true;
}
```

### 埃拉托斯特尼筛法
> 列出所有小質數最有效的方法之一，减治算法思想，空间换时间思想，缓存思想。Time complexity: O(n log log n)

给出要筛数值的范围n， 将[2, n]中所有的非质数剔除，构造一个可查询质数的表，而后还可以多次使用。先用2去筛，即把2留下，把2的倍数剔除掉；再用下一個質數，也就是3筛，把3留下，把3的倍数剔除掉；接下去用下一個質數5筛，把5留下，把5的倍数剔除掉；不斷重複下去......。

```c
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
    // 创建质数表
    char* isPrimeTable = eratosthenes(gen(n+1, 1), n);

    // 查询n是否为质数
    bool result = isPrimeTable[n] ? true : false;

    // 释放质数表
    free(isPrimeTable);
    return result;
}
```