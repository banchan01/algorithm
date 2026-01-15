#include <bits/stdc++.h>
using namespace std;
int n,m,_max=-1;
char arr[55][55];
int visited[55][55];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void bfs(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push({y,x});

    while(q.size()) {
        tie(y,x) = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny <0 || nx >=m || ny>=n) continue;
            if(arr[ny][nx]=='W') continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x]+1;
            q.push({ny,nx});
            _max = max(_max, visited[ny][nx]);
        }
    }
    return;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]=='L') {
                memset(visited,0,sizeof(visited));
                bfs(i,j);
            }
        }
    }
    cout << _max-1 << '\n';
    return 0;
}