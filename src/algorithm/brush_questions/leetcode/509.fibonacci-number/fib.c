

int fib(int N){
    if (N < 2) return N;

    int pre = 0;
    int result = 1;
    for (int i = 2; i <= N; i++) {
        int t = result;
        result = result + pre;
        pre = t;
    }
    return result;
}