#include<bits/stdc++.h>
using namespace std;


int main(){
    int nodes,edges;
    cin >> nodes >> edges;
    
    vector<int> adjacency_list[nodes];

    for(int i=0;i<edges;i++){
        int u, v;
        cin >> u >> v;
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    for(int i=0;i<nodes;i++){
        cout << i <<": ";
        for(auto val:adjacency_list[i]){
            cout << val << ' ';
        }
        cout << endl;
    }
}