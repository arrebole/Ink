#include "interpolationSearch.hpp"
#include <iostream>

using namespace std;

int main()
{
    int a[] = {1, 3, 5, 7, 8, 10, 13, 16, 18, 20, 23, 26, 28, 30, 32, 25, 37, 40};
    cout << interpolationSearch(a, 18, 18) <<endl;
    return 0;
}