#include <bits/stdc++.h>

using namespace std;

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
        // 从栈中取一个元素
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
                // 如果没有查询过，则把该元素入栈，并标记
                qu.push(node);
                seen.insert(node);
            }
        }
        cout << vertex << endl;
    }
}

int main()
{
    // 邻接链表法，表示图。
    map<string, vector<string>> graph;
    graph["A"] = {"B", "C"};
    graph["B"] = {"A", "C", "D"};
    graph["C"] = {"A", "B", "D", "E"};
    graph["D"] = {"B", "C", "E", "F"};
    graph["E"] = {"C", "D"};
    graph["F"] = {"D"};

    bfs(graph, "A");

    return 0;
}