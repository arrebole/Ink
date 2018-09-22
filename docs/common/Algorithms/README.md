

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



### # 算法索引

#### 2.1、暴力法

#### 2.2、减治法

#### 2.3、分治法

#### 2.4、变治法

#### 2.5、动态规划

#### 2.6、贪婪技术

#### 2.7、迭代改进

#### 2.8、算法能力的极限

#### 2.9、超越算法的极限

#### 3.0、收录

+ 辗转相除
+ 斐波那契数列
+ 汉诺特













## 3.0 收录

#### 3.0.1 辗转相除法求最大公约数（欧几里得算法）

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



#### 3.0.2 斐波那契数列

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

    /*
        循环交换 f0->f1 f1->sum sum->f0+f1
    */
    for (int i = 3; i <= n; i++)
    {
        sum = f0 + f1;
        f0 = f1;
        f1 = sum;
    }

    return sum;
}
```



#### 3.0.3 汉诺塔（Hanoi Tower）

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

