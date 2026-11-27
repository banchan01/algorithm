#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        map<string, int> m;
        int t; cin >> t;
        for(int j=0; j<t; j++) {
            string a,b; cin >> a >> b;
            m[b] += 1;
        }
        int ret = 1;
        for (auto [k,v] : m) {
            ret *= v+1;
        }
        cout << ret-1 << '\n';
    }
}