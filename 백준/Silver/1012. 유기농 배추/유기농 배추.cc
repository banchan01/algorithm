#include <bits/stdc++.h>
using namespace std;

int t, m, n, k, cnt;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int grid[55][55];
bool visited[55][55];

void DFS(int y, int x) {
    visited[y][x] = true;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
        if(grid[ny][nx]==1 && visited[ny][nx]==false) {
            DFS(ny,nx);
        }
    }
    return;
}




int main() {
    cin >> t;
    for(int T=0; T<t; T++) {
        cnt =0;
        fill(&grid[0][0], &grid[0][0] + 55 * 55, 0);
        fill(&visited[0][0], &visited[0][0] + 55 * 55, 0);
        
        // 입력받기
        cin >> m >> n >> k;
        for(int i=0; i<k; i++) {
            int a,b;
            cin >> a >> b;
            grid[b][a] = 1;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1 && visited[i][j]==false) {
                    cnt++;
                    DFS(i,j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}