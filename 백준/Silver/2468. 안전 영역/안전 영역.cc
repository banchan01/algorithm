#include <bits/stdc++.h>
using namespace std;

int n, result =0 ,cnt=0,mini = 1000, maxi = -1;
int grid[104][104];
int tgrid[104][104];
int visited[104][104];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void DFS(int y, int x) {
    visited[y][x] = 1;
    for(int i=0;i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
        if(tgrid[ny][nx]>0 && visited[ny][nx] == 0) {
            DFS(ny,nx);
        }
    }
    return;
}


int main() {
    
    // 입력받기
    cin >> n;

    for (int i =0;i<n;i++) {
        for(int j=0; j<n; j++) {
            int a;
            cin >> a;
            if(a<mini) mini = a;
            if (a > maxi) maxi = a;
            grid[i][j] = a;
            tgrid[i][j] = a;
        }
    }

    for(int candi=0; candi<=maxi; candi++) {
        // 초기화
        cnt = 0;
        fill(&visited[0][0], &visited[0][0]+104*104, 0);
        copy(&grid[0][0], &grid[0][0]+104*104, &tgrid[0][0]);
        
        // 잠수된 공간 지우기
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] <= candi) tgrid[i][j] = -1;
            }
        }

        // DFS
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(tgrid[i][j]>0 && visited[i][j]==0) {
                    DFS(i,j);
                    cnt += 1;                    
                }
            }
        }

        if(cnt >= result) result = cnt;
    }
    cout << result;
}