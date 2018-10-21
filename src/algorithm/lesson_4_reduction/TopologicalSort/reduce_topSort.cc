#include <bits/stdc++.h>

using namespace std;

class graph
{
  protected:
    int v;          // 顶点个数
    list<int> *adj; //邻接表
    int *indegree;  // 记录顶点入度
    queue<int> q;   //存放入度为0的顶点
  public:
    graph(int V);
    ~graph();
    void addEdge(int v, int w); //添加边
    bool topSort();             //进行拓扑排序
};

graph::graph(int v)
{
    this->v = v;
    adj = new list<int>[v];

    this->indegree = new int[v];
    for (int i = 0; i < v; i++)
    {
        this->indegree[i] = 0;
    }
}

graph::~graph()
{
    delete[] adj;
    delete[] indegree;
}

void graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    ++indegree[w];
}

bool graph::topSort()
{
    int count = 0;
    for (int i = 0; i < this->v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        cout << vertex << endl;
        count++;
        // 将所有v指向的顶点的入度减1，并将入度减为0的顶点入栈
        list<int>::iterator itor = adj[vertex].begin();
        for (; itor != adj[v].end(); ++itor)
        {
            // 若入度为0，则入栈
            if (!(--indegree[*itor]))
                q.push(*itor);
        }
    }
    if (count < this->v)
        return false; // 没有输出全部顶点，有向图中有回路
    else
        return true; // 拓扑排序成功
}

int main()
{
    graph g(6); // 创建图
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topSort();
    return 0;
}
