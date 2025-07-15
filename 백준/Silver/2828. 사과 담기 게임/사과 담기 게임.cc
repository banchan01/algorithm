#include <bits/stdc++.h>
using namespace std;

int n,m,j,ed,st=0,cnt=0;
int scrn[15];

int main() {
    cin >> n >> m >> j;
    ed = m;
    while(j--) {
        int apl;
        cin >> apl;
        if(st<apl && apl<=ed) continue;
        else if(apl<=st) {
            cnt += st-apl+1;
            st = apl-1;
            ed = st + m;
        }
        else if(ed<apl) {
            cnt += apl-ed;
            ed = apl;
            st = ed - m;
        }
    }
    cout << cnt;
}