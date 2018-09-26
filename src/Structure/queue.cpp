#include <iostream>

using namespace std;

struct queue
{
    int data[100];
    int head;
    int tail;
};


int main(int argc, char const *argv[])
{
    //定义q是一个int队列,并初始化
    struct queue q;
    q.head = 0;
    q.tail = 0;

    // 向队列插入10个数据
    for(int i=0;i<10;i++){
        cin >> q.data[q.tail];
        q.tail++;
    }

    // 启动队列
    while(q.head < q.tail)
    {
        // 打印队首
        cout << q.data[q.head]<<" ";
        q.head++;

        // 队尾追加
        q.data[q.tail] = q.data[q.head];
        q.tail++;
        q.head++;
    }
    return 0;
}
