#include <iostream>

using namespace std;

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

int main()
{

    return 0;
}