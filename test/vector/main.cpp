#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vx;
    cout << "start" <<endl;
    for (int i = 0; i < 10; i++)
    {
        vx.push_back(i);
        cout << vx[i] << " ";
    }
    cout << endl;
    for (vector<int>::iterator i = vx.begin(); i != vx.end();)
    {
        if (*i == 5)
        {
            vx.erase(i);
        }
        else
            i++;
    }

    for (int i = 0; i < vx.size(); i++)
    {
        cout << vx[i] << " ";
    }
    return 0;
}