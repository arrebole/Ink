/* ----------------------------------------
 * 
 * 试除法判断质数
 *
 * ---------------------------------------- */

#include <stdbool.h>
#include <math.h>
#include <assert.h>

// isPrime 检测n是不是素数 O(sqrt(n))
bool isPrime(int n) {
    assert(n >= 2);
    int lo = 1, hi = sqrt(n);
    while(++lo <= hi) {
        if (n % lo == 0) return false;
    }
    return true;
}