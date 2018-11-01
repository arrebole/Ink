#include "lomutoPartition.h"
/**
 *  lomuto划分：求数列中值
 *  架构：减治法-减可变规模-lomuto划分
 *  @params l,r,需要规划的开始端和结束端
*/
int lomutoPartition(int a[], int l,int r)
{
    int p = a[0];
    int s = l;
    for (int i = l + 1; i <= r; i++)
    {
        // 如果比p小则扩大s段
        if (a[i] < p)
        {
            s++;
            int t = a[s];
            a[s] = a[i];
            a[i] = t;
        }
    }
    return s;
}

