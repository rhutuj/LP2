#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &graph, vector<bool> &visi, queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int start = q.front();
    q.pop();
    visi[start] = true;
    cout << start << " ";
    for (int i : graph[start])
    {
        if (!visi[i])
        {
            visi[i] = true;
            q.push(i);
        }
    }
    bfs(graph, visi, q);
}
void addedge(vector<vector<int>> &graph, int v)
{
    int e;
    cout << "Enter the number of edges in the graph";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter the edge" << endl;
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < v; i++)
    {
        cout << i << " => ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(vector<vector<int>> &graph, vector<bool> &visi, int v)
{
    cout << v << " ";
    visi[v] = true;
    for (int i : graph[v])
    {
        if (!visi[i])
        {
            visi[i] = true;
            dfs(graph, visi, i);
        }
    }
}

int main()
{
    int v;
    cout << "Enter the number of vertices" << endl;
    cin >> v;

    vector<vector<int>> graph(v);
    vector<bool> visi(v, false);
    vector<bool> visi2(v, false);
    // vector<int> visited(v, false);
    addedge(graph, v);
    int start;
    cin >> start;
    queue<int> q;
    q.push(start);
    dfs(graph, visi, start);
    bfs(graph, visi2, q);

    return 0;
}
