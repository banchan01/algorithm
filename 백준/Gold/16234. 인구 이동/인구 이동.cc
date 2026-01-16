#include <bits/stdc++.h>
using namespace std;
int n,l,r,total_pop=0;
int tmp_pop=0, result = 0;
int arr[55][55];
int visited[55][55];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector<pair<int, int>> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    v.push_back({y,x});
    total_pop += arr[y][x];
    
    for(int i=0;i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
        if(visited[ny][nx]) continue;
        int _dist = abs(arr[y][x]-arr[ny][nx]);
        if(_dist>=l && _dist<=r) {
            dfs(ny,nx);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l >> r;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }


    while(true) {
        bool flag = false;
        memset(visited, 0, sizeof(visited));
        v.clear(); total_pop=0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(visited[i][j]==0) {
                    v.clear();
                    total_pop=0;
                    dfs(i,j);

                    if(v.size()>1) {
                        flag=true;
                        tmp_pop = total_pop/v.size();
                        for(auto a : v) {
                            arr[a.first][a.second] = tmp_pop;
                        }
                    }
                }
            }
        }
        if(!flag) break;
        result++;
    }
    cout << result << '\n';
    return 0;
}