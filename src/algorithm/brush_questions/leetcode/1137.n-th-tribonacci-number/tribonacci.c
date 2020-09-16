
int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int r1 = 0, r2 = 1, r3 = 1;
    while (--n >= 2) {
        int t3 = r3, t2 = r2;
        r3 = r3 + r2 + r1;
        r2 = t3;
        r1 = t2;
    }
    return r3;
}