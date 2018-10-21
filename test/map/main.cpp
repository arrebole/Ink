#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    map<string, string> iMap;
    cout << iMap.empty() << endl;
    iMap["A"] = "a";
    cout << iMap.empty() << endl;
    for (map<string, string>::iterator it = iMap.begin(); it != iMap.end();)
    {
        if (it->first == "A")
            iMap.erase(it++);
        else
            it++;
    }
    cout << iMap.empty() << endl;
    return 0;
}