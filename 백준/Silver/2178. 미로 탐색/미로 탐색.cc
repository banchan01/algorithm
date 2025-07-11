#include <bits/stdc++.h>

using namespace std;

int n,m;
int grid[104][104];
int visited[104][104];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
queue<pair<int,int>> q;

void BFS(int y, int x) {
    visited[y][x] = 1;
    q.push({y,x});
    while(q.size()) {
        pair<int,int> head = q.front();
        q.pop();
        for(int i=0;i<4; i++) {
            int ny = head.first + dy[i];
            int nx = head.second + dx[i];

            if (ny<0 || nx <0 || ny>=n || nx>=m) continue;
            if(grid[ny][nx] && visited[ny][nx] == 0) {
                q.push({ny,nx});
                visited[ny][nx] = visited[head.first][head.second] + 1;
            }
        }
    }
    return;
}


int main() {
    // 입력받기
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        string a;
        cin >> a;
        vector<int> v;
        for(char c : a) {
            v.push_back(c-'0');
        }
        for (int j=0; j<m; j++) {
            grid[i][j] = v[j];
        }
    }

    // BFS
    BFS(0,0);
    cout << visited[n-1][m-1];
    return 0;
}