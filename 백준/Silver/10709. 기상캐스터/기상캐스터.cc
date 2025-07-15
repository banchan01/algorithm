#include <bits/stdc++.h>
using namespace std;


int h,w;
bool flag = false;
int grid[105][105];
int visited[105][105];

int main() {
    cin >> h >> w;
    fill(&visited[0][0],&visited[0][0]+105*105,-1);
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            char a;
            cin >> a;
            if(a=='c') visited[i][j] = 0;
            grid[i][j] = a;
        }
    }

    for(int i=0; i<h; i++) {
        int n=1;
        flag = false;
        for(int j=0; j<w; j++) {
            if(visited[i][j]==0) {
                flag = true;
                n = 1;
                continue;
            }
            if(flag && visited[i][j]== -1 ) {
                visited[i][j] = n;
                n++;
            }
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}