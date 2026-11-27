#include <bits/stdc++.h>
using namespace std;

int cnt[105];

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    for(int i=0; i<3; i++) {
        int s,e;
        cin >> s >> e;
        for(int j=s; j<e;j++) {
            cnt[j] += 1;
        }
    }
    int ret=0;
    for(int i=0; i<104; i++) {
        if(cnt[i]==1) {
            ret += a;
        }
        else if(cnt[i]==2) {
            ret += (2*b);
        }
        else if(cnt[i]==3) {
            ret += (3*c);
        }
        else continue;
    }
    cout << ret;
    return 0;
}