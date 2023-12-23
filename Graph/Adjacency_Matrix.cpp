#include<bits/stdc++.h>
using namespace std;



int main(){
    int nodes,edges;
    cin >> nodes >> edges;
    
    int adjacency_matrix[nodes][nodes] = {};

    for(int i=0;i<edges;i++){
        int u, v;
        cin >> u >> v;
        adjacency_matrix[u][v] = 1;
        adjacency_matrix[v][u] = 1;
    }

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout << adjacency_matrix[i][j] << ' ';
        }
        cout << endl;
    }
}