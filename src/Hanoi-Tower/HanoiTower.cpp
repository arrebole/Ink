#include <iostream>

using namespace std;

void hanoiTower(int n, char a, char b, char c, unsigned int *count);

int main()
{
    unsigned int test;
    // 统计步数
    unsigned int flag = 0;
    cin >> test;

    hanoiTower(test, 'A', 'B', 'C', &flag);

    return 0;
}

void hanoiTower(int n, char a, char b, char c, unsigned int *count)
{
    // 步数+1
    (*count)++;
    if (n == 1)
    {
        cout << *count << ": " << a << " -> " << c << endl;
    }
    else
    {
        //第一步，A借助C，将n-1个盘子移到B;
        hanoiTower(n - 1, a, c, b, count);
        //第二步，将A上剩余的一个盘移到C;
        cout << *count << ": " << a << " -> " << c << endl;
        //第三步，将B上的 n-1个盘子移到C。
        hanoiTower(n - 1, b, a, c, count);
    }
}
