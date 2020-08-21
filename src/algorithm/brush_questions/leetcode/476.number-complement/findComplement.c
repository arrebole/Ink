
unsigned int bitLen(int num) {
    int result = 0;
    while (num != 0) {
        num = num >> 1;
        result++;
    }
    return result;
}

int findComplement(int num) {
    unsigned int result = num;
    unsigned int space = 32 - bitLen(num);
    return ~(result << space) >> space;
}