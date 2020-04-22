
// BruteForceStringMatch 在data中查准匹配模式的字串， 返回字串的首索引
// 时间复杂度： 平均 Θ(n) 最差( data_len * pattern_len )
int BruteForceStringMatch(char* data, int data_len, char* pattern, int pattern_len) {
    for (int i = 0; i <= (data_len - pattern_len); i++) {
        int j = 0;
        while (j < pattern_len && pattern[j] == data[i + j]) {
            j++;
            if (j == pattern_len) return i;
        }
    }
    return -1;
}




