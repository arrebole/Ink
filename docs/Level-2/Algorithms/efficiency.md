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

##### 递归版本

```c++
int Fib(int n)
{
    if(n<=1){
        return 1;
    }
    return Fib(n-1)+ Fib(n-2);
}
```



##### 迭代算法

```c++
long long Fib(long long N)
{
    long long first = 1;
    long long second = 1;
    long long ret = 0;
    for (int i = 3; i <= N; ++i)
    {
        ret = first + second;
        first = second;
        second = ret;
    }
    return second;
}
```

