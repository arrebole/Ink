#include <string.h>
#include <stdbool.h>

// lengthOfLastWord 最后一个单词的长度
int lengthOfLastWord(char* s){
    // 获取字符串长度
    int len = (int)strlen(s);
    if (len == 0) return 0;

    // 🗡 逆向迭代 双指针技巧-快慢指针
    int r = len -1, l = r;
    while (r >= 0){
        // r -> 右边第一个字符
        if(s[r] == ' '){
            r--;
            l--;
            continue;
        }
        // l -> 右边第一个空格
        while (l >= 0 && s[l] != ' ') l--;
        break;
    }
    
    return r - l;
}