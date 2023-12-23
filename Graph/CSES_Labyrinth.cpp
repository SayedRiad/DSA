#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, s_i, s_j, e_i, e_j;
int visited[N][N];
char direction[N][N], ans[1000000];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int level[N][N];


void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    
    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            
            int nx = head.first + dx[i];
            int ny = head.second + dy[i];
    
            if(nx>=0 and nx<n and ny>=0 and ny<m and !visited[nx][ny]){
                
                if(i==0)
                    direction[nx][ny] = 'R';
                else if(i==1)
                    direction[nx][ny] = 'L';
                else if(i==2)
                    direction[nx][ny] = 'U';
                else
                    direction[nx][ny] = 'D';

                level[nx][ny] = level[head.first][head.second]+1;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    
}

int main(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            visited[i][j] = (s[j]=='#');
            if(s[j]=='A'){
                s_i = i, s_j = j;
            }
            else if(s[j]=='B'){
                e_i = i, e_j = j;
            }
        }
    }

    BFS(s_i,s_j);

    if(visited[e_i][e_j]){
        cout << "YES\n";
        int x = level[e_i][e_j];
        cout << x << endl;
        for(int i=x-1;i>=0;i--){
            ans[i] = direction[e_i][e_j];
            if(ans[i]=='R')
                e_j--;
            else if(ans[i]=='L')
                e_j++;
            else if(ans[i]=='U')
                e_i++;
            else if(ans[i]=='D')
                e_i--;
        }

        for(int i=0;i<x;i++){
            cout << ans[i];
        }
        cout << endl;
        return 0;
    }

    cout << "NO\n";
   
    return 0;
}


