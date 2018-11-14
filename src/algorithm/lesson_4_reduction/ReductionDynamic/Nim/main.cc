#include <iostream>
#include "nim.h"

using namespace std;

int main()
{
    int n, limit;
    cin >> n >> limit;
    
    if (nim(n, limit))
        cout << "victory" << endl;
    else
        cout << "failure" << endl;

    return 0;
}