#include <assert.h>

extern int tribonacci(int n);

int main() {
    assert(tribonacci(0) == 0);
    assert(tribonacci(1) == 1);
    assert(tribonacci(2) == 1);
    assert(tribonacci(3) == 2);
    assert(tribonacci(4) == 4);
}