# 算法效率分析



## 非递归算法的数学分析









## 递归算法的数学分析

#### 斐波那契数列

##### 低效算法

```c++
int Fib(int n)
{
    if(n<=1){
        return 1;
    }
    return Fib(n-1)+ Fib(n-2);
}
```



##### 高效算法

```c++
int Fib(int n)
{
    int f[n] = {0};
    f[0] = 0,f[1] = 1;
    for(int i = 2;i<n;i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}
```

