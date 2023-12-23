#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
// int maze[N][N];
int visited[N][N];
int n,m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

// bool is_inside(pair<int, int> coord){
//     int x = coord.first;
//     int y = coord.second;

//     if(x >= 0 and x < n and y >= 0 and y < m){
//         return true;
//     }
//     return false;
// }

// bool is_safe(pair<int, int> coord){
//     int x = coord.first;
//     int y = coord.second;

//     if(maze[x][y] == -1){
//         return false;
//     }
//     return true;
// }

void BFS(pair<int, int> src){
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = 1;

    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            //pair<int, int> adj_node = {new_x, new_y};
            if(new_x>=0 and new_x<n and new_y>=0 and new_y<m  and !visited[new_x][new_y]){
                q.push({new_x, new_y});
                visited[new_x][new_y] = 1;
            }
        }
    }
}

// pair<int, int> find_unvisited(){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(visited[i][j]==0 and maze[i][j]==0){
//                 return {i, j};
//             }
//         }
//     }
//     return {-1, -1};
// }



int main(){
    
    cin >> n >> m;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            if(s[j] == '#'){
                visited[i][j] = 1;
            }
        }
    }

    int room_cnt = 0;
    // while(1){
    //     pair<int, int> unvisited_cell = find_unvisited();
    //     if(unvisited_cell == pair<int, int>(-1, -1)){
    //         break;
    //     }
    //     BFS(unvisited_cell);
    //     room_cnt++;
    // }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                BFS({i,j});
                room_cnt++;
            }
        }
    }
    cout << room_cnt << endl;
}