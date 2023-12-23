#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
int level[N];
int visited2[N];
int level2[N];
vector<int> adj_list[N];

void BFS(int src){
    queue<int> q;
    q.push(src);
    level[src] = 0;
    visited[src] = 1;

    while(!q.empty()){
        int head = q.front();
        q.pop();

        cout << head << ' ';
        for(auto adj_node:adj_list[head]){
            if(!visited[adj_node]){
                q.push(adj_node);
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
            }
        }
    }
    cout << "\n";
}

void DFS(int node){
    cout << node << ' ';
    visited2[node] = 1;

    for(auto adj_node:adj_list[node]){
        if(!visited2[adj_node]){
            
            DFS(adj_node);
            level2[adj_node] = level2[node] + 1;
        }
    }
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=0;i<edges;i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 0;
    BFS(src);
    DFS(src);
    cout << "\n";
    for(int i=0;i<nodes;i++){
        cout << "Node-" << i<<": Level: "<<level[i]<<"\n";
    }
    cout << "\n";
    for(int i=0;i<nodes;i++){
        cout << "Node-" << i<<": Level: "<<level2[i]<<"\n";
    }
    return 0;
}