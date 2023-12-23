#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int visited[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void DFS(int x, int y){
    visited[x][y] = 1;

    for(int i=0;i<4;i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(new_x>=0 and new_x<n and new_y>=0 and new_y<m and !visited[new_x][new_y]){
            DFS(new_x, new_y);
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            visited[i][j] = (s[j] == '#');
        }
    }

    int room_cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                DFS(i, j);
                room_cnt++;
            }
        }
    }

    cout << room_cnt << "\n";
    return 0;
}