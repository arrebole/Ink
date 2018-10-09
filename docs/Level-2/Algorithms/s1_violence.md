# 暴力法

## 选择排序和冒泡排序

#### 选择排序

>时间复杂度：θ(n^2)  但键的交换次数为 θ(n); 
>
>原理：遍历比较，选择最小的交换。

```c++
/**
 *  选择排序 参数为需要排序的数组，数组的长度
 *  时间复杂度：θ(n^2) 键的交换次数为 θ(n); 
 */
void selection_sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int minKey = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minKey])
            {
                minKey = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minKey];
        arr[minKey] = temp;
    }
}
```



#### 冒泡排序

>时间复杂度：θ(n^2)  键的交换次数为 θ(n^2);
>
>原理：a[i]与a[i+1]比较 



```c++
/**
 *  冒泡排序
 */
void bubble_sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {           
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
            }
        }
    }
}
```



## 顺序查找和蛮力字符串匹配

