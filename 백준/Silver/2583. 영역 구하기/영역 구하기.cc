#include <bits/stdc++.h>
using namespace std;

int m,n,k,area=0,cnt=0;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int grid[104][104];
int visited[104][104];
vector<int> v;

int DFS(int y, int x) {
    visited[y][x] = 1;
    area += 1;

    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || nx<0 || ny>=m || nx>=n) continue;
        if(grid[ny][nx]>0 && visited[ny][nx] == 0) {
            DFS(ny,nx);
        }
    }
    return area;
}

int main() {
    fill(&grid[0][0],&grid[0][0]+104*104,1);
    // 색 칠하기
    cin >> m >> n >> k;
    for (int i=0; i<k; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int s=m-d; s<m-b; s++) {
            for(int g=a; g<c; g++) {
                grid[s][g] = -1;
            }
        }
    }
    //DFS
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            area = 0;
            if(grid[i][j]>0 && visited[i][j] == 0) {
                area = DFS(i,j);
                v.push_back(area);
                cnt += 1;
            }
        }
    }
    cout << cnt << '\n';

    sort(v.begin(),v.end());
    for (int n : v) {
        cout << n << ' ';
    }
    return 0;
}