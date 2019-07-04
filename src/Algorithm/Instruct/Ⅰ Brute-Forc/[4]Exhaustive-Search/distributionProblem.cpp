#include <iostream>
#include <stdio.h>

using namespace std;

/**
 *  通过矩阵穷举查找分配问题
 *  暴力法-穷举查找-分配问题
 *  以4*4为例
 * 
*/
void distribution(int a[][4])
{
    int length = 4;
    int height = 4;
    int count = 0;
    for (int i = 0; i < height; i++)
    {
        int one = a[i][0];
        for (int j = 0; j < height; j++)
        {
            int two = a[j][1];
            for (int k = 0; k < height; k++)
            {
                int tree = a[k][2];
                for (int l = 0; l < height; l++)
                {
                    int four = a[l][3];
                    int res = one + two + tree + four;
                    count++;
                    printf("%d+%d+%d+%d=%d\n", one, two, tree, four, res);
                }
            }
        }
    }
    cout << "Count statistics: "<<count << endl;
}

int main()
{
    int a[4][4] = {{9, 2, 7, 8}, {6, 4, 3, 7}, {5, 8, 1, 8}, {7, 6, 9, 4}};
    distribution(a);
    return 0;
}