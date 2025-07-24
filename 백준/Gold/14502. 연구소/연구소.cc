#include <bits/stdc++.h>
using namespace std;

int n,m, area = 0,result = -1;
int grid[10][10];
int visited[10][10];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

vector<pair<int,int>> virus;
vector<pair<int,int>> wall;

void DFS(int y, int x) {
    visited[y][x] = 1;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny<0 || nx <0 || ny>=n || nx>=m) {
            continue;
        }
        if (visited[ny][nx] == 0 && grid[ny][nx] != 1) {
            DFS(ny,nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    // 입력받기
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m;j ++) {
            cin >> grid[i][j];
            // 기본 벽 세울 후보 정하기
            if(grid[i][j] == 0) {
                wall.push_back({i,j});
            }
            // 바이러스 위치 저장
            if(grid[i][j]==2) {
                virus.push_back({i,j});
            }
        }
    }

    for(int i=0; i<wall.size(); i++) {
        for(int j=0; j<i; j++) {
            for(int k=0; k<j; k++) {
                grid[wall[i].first][wall[i].second] = 1;
                grid[wall[j].first][wall[j].second] = 1;
                grid[wall[k].first][wall[k].second] = 1;

                for(auto pos : virus) {
                    DFS(pos.first,pos.second);
                }

                for(int a=0; a<n; a++) {
                    for(int b=0; b<m; b++) {
                        if(visited[a][b]==0 && grid[a][b] != 1) {
                            area++;
                        }
                    }
                }

                result = max(result,area);
                grid[wall[i].first][wall[i].second] = 0;
                grid[wall[j].first][wall[j].second] = 0;
                grid[wall[k].first][wall[k].second] = 0;
                area = 0;
                fill(&visited[0][0],&visited[0][0]+10*10,0);
            }
        }
    }

    cout << result;
    return 0;

}