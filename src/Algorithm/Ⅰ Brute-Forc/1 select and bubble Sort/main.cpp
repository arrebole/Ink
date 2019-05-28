#include <iostream>

using namespace std;

/**
 *
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

/**
 *
 *  冒泡排序 参数为需要排序的数组，数组的长度
 *  时间复杂度：θ(n^2) 键的交换次数为 θ(n^2); 
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

int main()
{
    int arr1[6] = {3, 2, 4, 1, 5, 0};
    int arr2[6] = {3, 2, 4, 1, 5, 0};
    selection_sort(arr1, 6);
    bubble_sort(arr2, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << "arr1: "<< arr1[i] << endl;
        cout << "arr2: "<< arr2[i] << endl;
    }
    return 0;
}