# 算法效率分析



## 非递归算法的数学分析









## 递归算法的数学分析

#### 辗转相除法

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



#### 斐波那契数列

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



#### 汉诺塔

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



## 排序

### 桶排序

>时间复杂度 O( M+N );
>
>特点：标记排序，消耗内存但是速度非常快

```python

```



### 冒泡排序

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



### 快速排序

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

