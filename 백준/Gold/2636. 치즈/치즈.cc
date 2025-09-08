#include <bits/stdc++.h>
using namespace std;
int a[104][104], visited[104][104];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int m,n,cnt=0,cnt1;
vector <pair<int,int>> v;

void go(int y, int x) {
    visited[y][x] = 1;

    if(a[y][x]== 1){
        v.push_back({y,x});
        return;
    }
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || nx <0 || ny >=m || nx >=n) continue;
        if (visited[ny][nx] == 1) continue;
        go(ny,nx);
    }
    return;
}



int main() {
    // 입력받기
    cin >> m >> n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    //DFS
    while(true) {
        fill(&visited[0][0], &visited[0][0]+ 104*104, 0);
        v.clear();
        go(0,0);
        cnt1 = v.size();
        for(pair<int,int> b : v) {
            a[b.first][b.second] = 0;
        }
        cnt++;

        bool flag = true;
        for(int i =0;  i<m; i++) {
            for(int j=0; j<n; j++) {
                if(a[i][j]==1) flag = false;
            }
        }
        if(flag) break;        
    }
    cout << cnt << '\n' << cnt1 << '\n';
    return 0;
}