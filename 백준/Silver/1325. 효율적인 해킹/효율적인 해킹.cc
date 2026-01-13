#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,tmp=-1;
vector<int> adj[10005];
bool visited[10005];
int result[10005];

int dfs(int here) {
    int ret =1;
    visited[here] = true;
    for(int there : adj[here]) {
        if(visited[there]==true) {
            continue;
        }
        ret += dfs(there);
    }
    return ret;
}


int main() {
    cin >> n >> m;
    // 값 넣기
    while(m--) {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    // 노드 별 dfs 돌리기
    for(int i = 1; i<=n; i++) {
        memset(visited, false, sizeof(visited));
        result[i] = dfs(i);
        tmp = max(result[i],tmp);
    }

    // 최댓값인거 출력
    for(int i=1; i<=n; i++) {
        if(result[i]==tmp) {
            cout << i << ' ';
        }
    }
    return 0;
}