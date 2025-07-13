#include <bits/stdc++.h>
using namespace std;

int n;
int grid[70][70];
int visited[70][70];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
string result;

void SRCH(int y,int x, int size) {
    int init = grid[y][x];
    for(int i=y; i < y+size; i++) {
        for(int j=x; j < x+size; j++) {
            if (grid[i][j] != init) {
                result.append("(");
                SRCH(y,x,size/2);
                SRCH(y, x+size/2, size/2);
                SRCH(y+size/2, x, size/2);
                SRCH(y+size/2, x+size/2, size/2);
                result.append(")");
                return;
            }
        }
    }
    result.append(to_string(init));
    return;
}

int main() {
    // 입력받기
    cin >> n;
    for(int i=0; i<n; i++) {
        string a;
        cin >> a;
        for(int j=0; j<n; j++) {
            grid[i][j] = a[j]-'0';
        }
    }
    SRCH(0,0,n);
    cout << result;
}