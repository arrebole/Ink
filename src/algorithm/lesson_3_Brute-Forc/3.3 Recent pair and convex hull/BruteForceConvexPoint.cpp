#include <bits/stdc++.h>

void BruteForceConvexPoint(double arr[][2], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        double x1 = arr[i][0];
        double y1 = arr[i][1];
        for (int j = i + 1; j < len; j++)
        {
            double x2 = arr[j][0];
            double y2 = arr[j][1];
            // 根据两点确定直线，在分析其他点和该直线的位置
            double a = y2 - y1;
            double b = x1 - x2;
            double c = x1 * y2 - y1 * x2;

            int above = 0; // 在直线上发
            int below = 0; // 在直线下方
            int on = 0;    // 在直线上
            for (int k = 0; k < len; k++)
            {
                double temp = a * arr[k][0] + b * arr[k][1];
                if (temp == c)
                {
                    on++;
                }
                else if (temp > c)
                {
                    above++;
                }
                else
                {
                    below++;
                }
            }
            // 如果其余点都在这条直线的一侧
            // 则这两点组成凸包线，为顶点
            if (above == 0 || below == 0)
            {

                printf("point: p(%.0lf,%.0lf) p(%.0lf,%.0lf)\n", arr[i][0], arr[i][1], arr[j][0], arr[j][1]);
            }
        }
    }
}

int main()
{
    double a[5][2] = {{0, 0}, {0, 10}, {10, 10}, {10, 0}, {1, 1}};
    BruteForceConvexPoint(a, 4);
    return 0;
}