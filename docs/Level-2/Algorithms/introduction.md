# 基本数据类型



## 线型结构

### 数组

> 最原始的数组是内存中连续的片段，一旦定义之后长度无法变更。数组用于存放相同类型的数据结构，存在 下标index 和 值value ，index从0开始；基本操作 **遍历，读取，修改**



**1、内存占用**

```c++
// 申请内存 为 10个int类型的长度，一个 int 在64位操作系统下 占用4字节（32 bit）
// 所以 array 占用 栈内存 10 * 4 byte = 10 * 32 bit = 40 byte = 320 bit
int array[10];
```



### 队列

> 队列是一种特殊的线性表，它只允许在表的前端（front）进行删除操作，而在表的后端（rear）进行插入操作，和栈一样。进行插入操作的端称为队尾，进行删除操作的端称为队头。队列中没有元素时，称为空队列。



**1、数组队列**

```c++
struct queue
{
    int data[100];
    int head;
    int tail;
};
```

```c++
//定义q是一个int队列,并初始化
struct queue q;
q.head = 0;
q.tail = 0;

// 向队列插入10个数据
for(int i=0;i<10;i++){
    cin >> q.data[q.tail];
    q.tail++;
}
```



```c++
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
```



**2、循环队列**

```

```



### 栈

> 栈（stack）它是一种运算受限的线性表。其限制是仅允许在表的一端进行插入和删除运算。这一端被称为栈顶，相对地，把另一端称为栈底。向一个栈插入新元素又称作进栈、入栈或压栈，它是把新元素放到栈顶元素的上面，使之成为新的栈顶元素；从一个栈删除元素又称作出栈或退栈，它是把栈顶元素删除掉，使其相邻的元素成为新的栈顶元素

**1、数组栈**

```c++
class stack
{
private:
  /* data */
  int *data;
  int top;
  int maxSize;

public:
  stack(int n)
  {
    maxSize = n;
    top = 0;
    data = new int[n];
  }
  ~stack()
  {
    delete[] data;
    data = NULL;
  }
  bool push(int n)
  {
    if (top > maxSize)
    {
      return false;
    }
    data[top] = n;
    top++;
    return true;
  }
  int pop()
  {
    if (top == 0)
    {
      return data[0];
    }
    top--;
    return data[top];
  }
};
```



```c++
int main()
{
    // 创建栈
    stack s(10);
    // 数字入栈
    for(int i=0;i<10;i++)
    {
        s.push(i);
    }
    // 出栈
    for(int i = 0;i<10;i++)
    {
        cout << s.pop() <<endl;
    }
    return 0;
}
```



### 链表

> 链表是一种物理[存储单元](https://baike.baidu.com/item/%E5%AD%98%E5%82%A8%E5%8D%95%E5%85%83/8727749)上非连续、非顺序的[存储结构](https://baike.baidu.com/item/%E5%AD%98%E5%82%A8%E7%BB%93%E6%9E%84/350782)，[数据元素](https://baike.baidu.com/item/%E6%95%B0%E6%8D%AE%E5%85%83%E7%B4%A0/715313)的逻辑顺序是通过链表中的[指针](https://baike.baidu.com/item/%E6%8C%87%E9%92%88/2878304)链接次序实现的。

**1、数组模拟的链表**

```c++
int data[101], right[101];
int i, n, t, len;

//往数组内存放数字
cin >> n;
for (i = 0; i <= n; i++)
{
    cin >> data[n];
}
len = n;
//初始right
for (i = 1; i <= n; i++)
{
    if (i != n)
        right[i] = i + 1;
    else
        right[i] = 0;
}

//输入插入的数
len++;
cin >> data[len];

// 将数插入
t = 1;
while (t != 0)
{
    if (data[right[t]] > data[len])
    {
        right[len] = right[t];
        right[t] = len;
        break;
    }
    t = right[t];
}
// 输出
t = 1;
while (t != 0)
{
    cout << data[t] << endl;
    t = right[t];
}
```



## 树型结构



## 图型结构



## 集合和字典

