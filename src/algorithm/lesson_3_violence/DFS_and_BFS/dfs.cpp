#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/**
 *  通过栈和邻接链表图实现 深度优先搜索
 *  暴力法-深度优先搜索
 * 
*/
void stack_dfs(map<string, vector<string>> graph, string s)
{
    // 搜索栈
    stack<string> st;
    // 跟踪是否已经到过
    set<string> seen;

    st.push(s);
    seen.insert(s);

    while (st.size() > 0)
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

void Recursive_dfs(map<string, vector<string>> graph, string s)
{

}


int main()
{
    // 邻接链表法，表示图。
    map<string, vector<string>> graph;
    graph["A"] = {"B", "C"};
    graph["B"] = {"A", "C", "D"};
    graph["C"] = {"A", "B", "D","E"};
    graph["D"] = {"B", "C", "E","F"};
    graph["E"] = {"C", "D"};
    graph["F"] = {"D"};

    stack_dfs(graph, "A");
    return 0;
}