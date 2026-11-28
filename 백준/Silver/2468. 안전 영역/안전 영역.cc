#include <bits/stdc++.h>
using namespace std;

int arr[105][105];
int visited[105][105];
int n, mn=9999999, ret =-1;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void dfs(int y, int x, int st) {
    visited[y][x] = 1;
    for(int i=0; i<4; i++) {
        int ny = dy[i] +y;
        int nx = dx[i] + x;
        if(ny<0 || ny>=n || nx<0 || nx>=n || arr[ny][nx] <=st) continue;
        if(visited[ny][nx]) continue;
        dfs(ny,nx,st);
    }
} 

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int st=0; st<=100; st++) {
        int tmp=0;
        fill(&visited[0][0], &visited[0][0] + 105*105, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j]<=st || visited[i][j]==1) continue;
                dfs(i,j,st); tmp++;
            }
        }
        ret = max(ret, tmp);
    }
    cout << ret << '\n';
    return 0;
}