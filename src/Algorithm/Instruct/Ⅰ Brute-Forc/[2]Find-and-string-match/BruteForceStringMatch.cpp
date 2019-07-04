/**
 * 蛮力法：
 * 顺序查找和字符串匹配
 * 
 */

#include <iostream>
#include <math.h>

using namespace std;

int BruteForceStringMatch(char t[], int t_len, char p[], int p_len)
{
    for (int i = 0; t_len - p_len; i++)
    {
        int j = 0;
        while (j < p_len && p[j] == t[i + j])
        {
            j++;
            if (j == p_len)
                return i;
        }
    }
    return -1;
}




