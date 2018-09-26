

## 数据结构与算法



 ###  # 结构索引

#### 1.1、线型结构

+ 数组
+ 队列
+ 栈
+ 链表

#### 1.2、树型结构

+ 二叉树

#### 1.3、图型结构



###  #重要的问题类型

#### 2.1、递归

+ 辗转相除
+ 斐波那契数列
+ 汉诺特

#### 2.2、排序

+ 桶排序
+ 冒泡排序
+ 快速排序



### # 算法索引

#### 3.1、暴力法

#### 3.2、减治法

#### 3.3、分治法

#### 3.4、变治法

#### 3.5、动态规划

#### 3.6、贪婪技术

#### 3.7、迭代改进

#### 3.8、算法能力的极限

#### 3.9、超越算法的极限



## 1.1 线型结构

#### @数组

>最原始的数组是内存中连续的片段，一旦定义之后长度无法变更。数组用于存放相同类型的数据结构，存在 下标index 和 值value ，index从0开始；基本操作 **遍历，读取，修改**



**1、内存占用**

```c++
// 申请内存 为 10个int类型的长度，一个 int 在64位操作系统下 占用4字节（32 bit）
// 所以 array 占用 栈内存 10 * 4 byte = 10 * 32 bit = 40 byte = 320 bit
int array[10];
```



#### @队列

>队列是一种特殊的线性表，它只允许在表的前端（front）进行删除操作，而在表的后端（rear）进行插入操作，和栈一样。进行插入操作的端称为队尾，进行删除操作的端称为队头。队列中没有元素时，称为空队列。



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



#### @栈

>栈（stack）它是一种运算受限的线性表。其限制是仅允许在表的一端进行插入和删除运算。这一端被称为栈顶，相对地，把另一端称为栈底。向一个栈插入新元素又称作进栈、入栈或压栈，它是把新元素放到栈顶元素的上面，使之成为新的栈顶元素；从一个栈删除元素又称作出栈或退栈，它是把栈顶元素删除掉，使其相邻的元素成为新的栈顶元素

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



#### @链表

>链表是一种物理[存储单元](https://baike.baidu.com/item/%E5%AD%98%E5%82%A8%E5%8D%95%E5%85%83/8727749)上非连续、非顺序的[存储结构](https://baike.baidu.com/item/%E5%AD%98%E5%82%A8%E7%BB%93%E6%9E%84/350782)，[数据元素](https://baike.baidu.com/item/%E6%95%B0%E6%8D%AE%E5%85%83%E7%B4%A0/715313)的逻辑顺序是通过链表中的[指针](https://baike.baidu.com/item/%E6%8C%87%E9%92%88/2878304)链接次序实现的。

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



## 2.1 递归

#### @辗转相除法

>求最大公约数（欧几里得算法）
>
>计算两个非负整数 p 和 q 的最大公约数：若q 是 0，则最大公约数为 p。否则，将 p 除以q 得到余数 r，p 和 q 的最大公约数即为 q 和r 的最大公约数。

递归实现

```java
public static int gcd(int p, int q)
{
    if(q==0) return p;
    int r = p % q;
    return acd(q, r);
    
}
```

循环实现

```go
func gcd(x,y int) int {
     for y != 0  {     
            x, y = y, x % y 
      }  
    return x
}
```



---



#### @斐波那契数列

>斐波那契数列又称：黄金分割数列、兔子数列，
>
>如果设F(n）为该数列的第n项（n∈N*），那么这句话可以写成如下形式：F(n)=F(n-1)+F(n-2)

递归实现

```c++

// 一般递归  时间复杂度O(2^N),空间复杂度O(n)   
int fibonacci(int n)
{
    if (n < 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

```



```c++
// 递归优化
int fibonacci(int a, int b, int n)
{
    if (n < 3)
    {
        return b;
    }

    return fibonacci(b, a + b, n - 1);
}
```



```c++
//迭代法
int fibonacci(int n)
{
    int f0 = 1;
    int f1 = 1;
    int sum = 0;
    if (n < 3)
    {
        return 1;
    }
    
    //循环交换 f0->f1 f1->sum sum->f0+f1
    for (int i = 3; i <= n; i++)
    {
        sum = f0 + f1;
        f0 = f1;
        f1 = sum;
    }

    return sum;
}
```



---



#### @汉诺塔

>有A,B,C三个柱子，将A柱子上的N个盘子（从大到小排列）移到C柱子上，每次只允许移动一个盘子，并且保证每个柱子上的盘子的排列都是从大到小



```c++
void hanoiTower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " -> " << c << endl;
    }
    else
    {
        hanoiTower(n - 1, a, c, b);
        cout  << ": " << a << " -> " << c << endl;
        hanoiTower(n - 1, b, a, c);
    }
}
```



## 2.2 排序

#### @桶排序

>时间复杂度 O( M+N );
>
>特点：标记排序，消耗内存但是速度非常快

```python

```



#### @冒泡排序

>##### 基于暴力法，时间复杂度O(N^2)]
>
>特点：双重嵌套循环，内存占用低，但耗时高；



```c++
template<typename T>
void bubble_sort(T arr[], int len)
{
    // i只是用于计数已经排完成的项，j用于遍历；
    int i, j;  T temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
        if (arr[j] > arr[j + 1])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
}
```



#### @快速排序

>##### 基于二分思想，分治法, 递归；时间复杂度：  最差 O( N^2 ), 平均 O( N*logN )
>
>特点：基准数归位，快速排序是最常用的排序，空间和时间都比较折中。

js版本

```javascript
/**
 * 快速排序
 * @param {arrayay<number>} array
 * @param {i:number} i
 * @param {j:number} j
 */
let array = [3, 6, 0, 3, 7, 9, 0, 4, 3];
QuickSort(array, 0, array.length - 1);

/**
 * 快速排序
 * @param {array<number>} array 
 * @param {number} left
 * @param {number} right
 */
function QuickSort(array, left, right) {
    if (left > right) {
        return
    }
    let base = array[left];
    let i = left;
    let j = right;

    while (i != j) {
        //从右向左扫描是否存在比基数小的数字
        while (array[j] >= base && i < j) {
            j--;
        }
        //从左向右扫描是否存在比基数大的数字
        while (array[i] <= base && i < j) {
            i++;
        }

        if (i < j) {
            //将大于基数的数字放置到右侧
            let temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    //更新基数
    array[left] = array[i];
    array[i] = base;

    //递归对左侧进行排序
    QuickSort(array, left, i - 1);
    //递归对右侧进行排序
    QuickSort(array, (i + 1), right);

}
```

go版本

```go
func quickSork(intSlice []int, left int, right int) {
	if left > right {
		return
	}
	basic := intSlice[left]
	i, j := left, right
	for i != j {
		for intSlice[j] >= basic && i < j {
			j--
		}
		for intSlice[i] <= basic && i < j {
			i++
		}
		if i < j {
			intSlice[i], intSlice[j] = intSlice[j], intSlice[i]
		}
	}
	intSlice[left], intSlice[i] = intSlice[i], basic
	quickSork(intSlice, left, i-1)
	quickSork(intSlice, i+1, right)
	return
}
```

