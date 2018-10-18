#include <bits/stdc++.h>

using namespace std;

void reduce_topsort(map<string, vector<string>> graph, string start)
{
    
}

int main()
{
    map<string, vector<string>> graph;
    graph["a"] = {"b", "c"};
    graph["b"] = {"e", "g"};
    graph["c"] = {"f"};
    graph["d"] = {"a", "b", "g", "f", "c"};
    graph["e"] = {};
    graph["f"] = {};

    /* code */
    return 0;
}
