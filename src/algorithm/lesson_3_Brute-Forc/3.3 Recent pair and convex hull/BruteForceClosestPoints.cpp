
#include <iostream>
#include <math.h>

using namespace std;

/**
 *
 *  使用蛮力算法求平面中距离最近的两个点
 *  @params 点(x,y)的数组p,数组的长度len。
 *  @return 两个最近点的距离
 */
double BruteForceClosestPoints(int p[][2],int len)
{
    int d = INT32_MAX;
    for (int i = 0; i < len - 1;i++)
    {
        for (int j = i + 1; j < len;j++)
        {
            int temp = (p[i][0] - p[j][0])*(p[i][0] - p[j][0]) + (p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
            d > temp ? d = temp : d = d;
        }
    }

    return sqrt(d);
}

int main()
{
    int p[4][2] = {{2, 5}, {0, 0}, {1, 1}, {9, 0}};
    cout << BruteForceClosestPoints(p, 4) << endl;
}