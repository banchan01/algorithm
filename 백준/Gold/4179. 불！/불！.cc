#include <bits/stdc++.h>
using namespace std;

int r,c,y,x,result=-1;
char arr[1005][1005];
pair<int,int> jh;
queue<pair<int,int>> q,p;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int jh_visited[1005][1005] ={0};
int fr_visited[1005][1005] ={0};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    fill(&fr_visited[0][0], &fr_visited[0][0] + 1005 * 1005, 987654321);
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        for(int j=0;j<c;j++) {
            cin >> arr[i][j];
            if(arr[i][j]=='J') jh = {j,i};
            if(arr[i][j]=='F') {
                fr_visited[i][j] = 1;
                q.push({i,j});
            }
        }
    }

    // 불 번지게 하기
    while(q.size()) {
        tie(y,x) = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
            if(fr_visited[ny][nx]!=987654321 || arr[ny][nx]=='#') continue;
            fr_visited[ny][nx] = fr_visited[y][x] + 1;
            q.push({ny,nx});
        }
    }

    // 지훈이 탈출 시작
    jh_visited[jh.second][jh.first] =1;
    p.push({jh.second,jh.first});
    while(p.size()) {
        tie(y,x) = p.front();
        p.pop();
        if(y==r-1 || x== c-1 ||y==0 || x==0) {
            result = jh_visited[y][x];
            break;
        }
        for(int i=0;i<4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx<0 || ny>=r || nx>=c || arr[ny][nx]=='#') continue;
            if(jh_visited[ny][nx]) continue;
            if(fr_visited[ny][nx]<=jh_visited[y][x]+1) continue;
            jh_visited[ny][nx] = jh_visited[y][x]+1;
            p.push({ny,nx});
        }
    }
    if(result>0) {
        cout << result << '\n';
    }
    else {
        cout << "IMPOSSIBLE \n";
    }
    return 0;
}