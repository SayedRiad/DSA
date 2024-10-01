#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int visited[N];
int color[N];

vector<int> adj_list[N];

bool DFS(int node)
{
    visited[node] = 1;

    for (auto adj_node : adj_list[node])
    {
        if (!visited[adj_node])
        {
            if (color[node] == 1)
                color[adj_node] = 2;
            else
                color[adj_node] = 1;

            bool is_bicolorable = DFS(adj_node);
            if (!is_bicolorable)
            {
                return false;
            }
        }
        else
        {
            if (color[node] == color[adj_node])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool is_bicolorable = true;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            color[i] = 1;
            bool ok = DFS(i);
            if (!ok)
            {
                is_bicolorable = false;
            }
        }
    }
    if (!is_bicolorable)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << color[i] << " ";
        }
    }
}