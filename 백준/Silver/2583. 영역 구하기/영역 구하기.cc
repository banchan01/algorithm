#include <bits/stdc++.h>
using namespace std;

int arr[105][105];
int visited[105][105];
int m,n,k;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector<int> ret;

void fill(int a, int b, int c, int d) {
    for(int i=b; i<d; i++) {
        for(int j=a; j<c; j++){
            arr[i][j] =1;
        }
    }
}

int dfs(int y, int x) {
    visited[y][x] = 1;
    int r =1;
    for(int i=0; i<4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny<0 || ny>=m || nx<0 || nx>=n || arr[ny][nx] == 1) continue;
        if(visited[ny][nx]) continue;
        r += dfs(ny,nx);
    }
    return r;
}

int main() {
    cin >> m >> n >> k;
    for(int i=0; i<k; i++) {
        int a,b,c,d; cin >> a>>b>>c>>d;
        fill(a,b,c,d);
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j]!=0 || visited[i][j]==1) continue;
            ret.push_back(dfs(i,j));
        }
    }
    sort(ret.begin(),ret.end());
    cout << ret.size() << '\n';
    for(int n : ret) {
        cout << n << ' ';
    }
    return 0;
}