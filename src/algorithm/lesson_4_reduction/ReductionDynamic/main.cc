#include <iostream>
#include "quickSelect.h"

using namespace std;

int main()
{
    int a[] = {1, 3, 4, 7, 9, 2, 0, 4, 5};
    printf("min 3th of a: %d", quickSelect(a, 9, 3));
    return 0;
}