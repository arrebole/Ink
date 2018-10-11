# 算法效率分析



## 非递归算法的数学分析

#### 数组最大值

```c++
// 时间复杂度：n
int maxElement(int arr[],int size)
{
    int maxVal = arr[0];
    for (int i = 0; i < size;i++)
    {
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }

    return maxVal;
}
```



#### 元素唯一性

```c++
// 判断数组元素是否唯一
bool uniqueElements(int arr[],int sinze)
{
    for (int i = 0; i < sinze-1;i++)
    {
        for (int j = i + 1; j < sinze;j++)
        {
            if(arr[i] == arr[j])
                return false;
        }
    }
        return true;
}
```





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

