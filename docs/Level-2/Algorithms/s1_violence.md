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

#### 顺序查找

>时间复杂度：T(n) 最好Ω(1), 最差 O(n)
>
>空间复杂度：S(n) = 1

```c++
// 暴力法——顺序查找
// 时间复杂度：T(n) = θ(n)
int SequentialSearch(int arr[], int len, int key)
{
    // 创建一个新数组 比原来数组长度+1
    int newArr[len + 1];
    for (int i = 0; i < len; i++)
    {
        newArr[i] = arr[i];
    }
    // 新数组最后一项为传入的 key
    newArr[len] = key;

    int j = 0;
    while (newArr[j] != key)
    {
        j++;
    }

    if (j == len)
    {
        return -1;
    }

    return j;
}
```



#### 蛮力法字符串匹配

>时间复杂度：T(n)最差 O(mn)
>
>空间复杂度： S（n）= 1

```c++
// t_len: t字符长度，不包括字符串 '\0'
// p_len: p字符长度，不包括字符串 '\0'
int BruteForceStringMatch(char t[], int t_len, char p[], int p_len)
{
    for (int i = 0; t_len - p_len; i++)
    {
        int j = 0;
        while (j < p_len && p[j] == t[i + j])
        {
            j++;
            if (j == p_len)
                return i;
        }
    }
    return -1;
}
```





## 最近对和凸包问题的蛮力算法

#### 最近对问题

>暴力法—蛮力求最近点
>
>时间复杂度：T(n) = θ(n^2)

```c++
/**
 *
 *  使用蛮力算法求平面中距离最近的两个点
 *  @params 点(x,y)的数组p,数组的长度len。
 *  @return 两个最近点的距离
 */
double BruteForceClosestPoints(int p[][2],int len)
{
    int d = INT32_MAX;
    for (int i = 0; i < len - 1;i++)
    {
        for (int j = i + 1; j < len;j++)
        {
            int temp = (p[i][0] - p[j][0])*(p[i][0] - p[j][0]) 
                + (p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
            d > temp ? d = temp : d = d;
        }
    }

    return sqrt(d);
}
```



#### 凸包问题

>暴力法—求凸包点
>
>时间复杂度：T(n) = O(n^3)

```c++
void BruteForceConvexPoint(double arr[][2], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        double x1 = arr[i][0];
        double y1 = arr[i][1];
        for (int j = i + 1; j < len; j++)
        {
            double x2 = arr[j][0];
            double y2 = arr[j][1];
            // 根据两点确定直线，在分析其他点和该直线的位置
            // ax + by = c
            double a = y2 - y1;
            double b = x1 - x2;
            double c = x1 * y2 - y1 * x2;

            int above = 0; // 在直线上发
            int below = 0; // 在直线下方
            int on = 0;    // 在直线上
            for (int k = 0; k < len; k++)
            {
                double temp = a * arr[k][0] + b * arr[k][1];
                if (temp == c)
                {
                    on++;
                }
                else if (temp > c)
                {
                    above++;
                }
                else
                {
                    below++;
                }
            }
            // 如果其余点都在这条直线的一侧
            // 则这两点组成凸包线，为顶点
            if (above == 0 || below == 0)
            {

                printf("point: p(%.0lf,%.0lf) p(%.0lf,%.0lf)\n"
                       , arr[i][0], arr[i][1], arr[j][0], arr[j][1]);
            }
        }
    }
}
```





## 穷举查找

#### 旅行商问题



#### 背包问题



#### 分配问题

>暴力法-穷举查找-分配问题
>
>时间复杂度：T(n) = O(n*n!)

```c++
/**
 *  通过矩阵穷举查找分配问题
 *  暴力法-穷举查找-分配问题
 *  以4*4为例
 * 
*/
void distribution(int a[4][4])
{
    int length = 4;
    int height = 4;
    for (int i = 0; i < height; i++)
    {
        int one = a[i][0];
        for (int j = 0; j < height; j++)
        {
            int two = a[j][1];
            for (int k = 0; k < height; k++)
            {
                int tree = a[k][2];
                for (int l = 0; l < height; l++)
                {
                    int four = a[l][3];
                    int res = one + two + tree + four;
                    printf("%d+%d+%d+%d=%d\n", one, two, tree, four, res);
                }
            }
        }
    }
}
```





## 深度优先搜索和广度优先搜索

#### 深度优先搜索

>暴力法-深度优先搜索
>
>时间复杂度：链表法 θ( |v| + |E| ) 矩阵法 θ( |v|^2 )



##### 图的表示

```c++
// 邻接链表法，表示图。
map<string, vector<string>> graph;
graph["A"] = {"B", "C"};
graph["B"] = {"A", "C", "D"};
graph["C"] = {"A", "B", "D","E"};
graph["D"] = {"B", "C", "E","F"};
graph["E"] = {"C", "D"};
graph["F"] = {"D"};

```



##### 直接通过栈实现

```c++
/**
 *  通过栈和邻接链表图实现 深度优先搜索
 *  暴力法-深度优先搜索
 *  输入图和起始点
*/
void dfs(map<string, vector<string>> graph, string s)
{
    // 搜索栈
    stack<string> st;
    // 跟踪是否已经到过
    set<string> seen;

    st.push(s);
    seen.insert(s);

    while (!st.empty())
    {
        // 从栈中取一个元素
        string vertex = st.top();
        st.pop();
        // 查询取出的元素
        vector<string> nodes = graph[vertex];
        // 遍历取出的元素
        for (int i = 0; i < nodes.size(); i++)
        {
            // 判断元素是否已经查询过
            string node = nodes[i];
            if (seen.find(node) == seen.end())
            {
                // 如果没有查询过，则把该元素入栈，并标记
                st.push(node);
                seen.insert(node);
            }
            
        }
        cout << vertex << endl;
    }
}
```



#### 广度优先搜索

>暴力法-广度优先搜索
>
>时间复杂度：链表法 θ( |v| + |E| ) 矩阵法 θ( |v|^2 )



##### 队列实现广度优先搜索

```c++
/**
 *  通过队列和邻接链表图实现 深度优先搜索
 *  暴力法-广度优先搜索
 *  输入图和起始点
*/
void bfs(map<string, vector<string>> graph, string s)
{
    // 搜索队列
    queue<string> qu;
    // 跟踪是否已经到过
    set<string> seen;

    qu.push(s);
    seen.insert(s);

    while (!qu.empty())
    {
        // 取出队列头
        string vertex = qu.front();
        qu.pop();
        // 查询取出的元素
        vector<string> nodes = graph[vertex];
        // 遍历取出的元素
        for (int i = 0; i < nodes.size(); i++)
        {
            // 判断元素是否已经查询过
            string node = nodes[i];
            if (seen.find(node) == seen.end())
            {
                // 如果没有查询过，则把该元素推入队列，并标记
                qu.push(node);
                seen.insert(node);
            }
        }
        cout << vertex << endl;
    }
}
```

