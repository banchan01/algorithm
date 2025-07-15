#include <bits/stdc++.h>
using namespace std;

int n,c,cnt=0;
map<int, int> m,seq;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second) {
        return seq[a.first]< seq[b.first];
    }
    return a.second>b.second;
}

int main() {
    cin >> n >> c;
    while(n--) {
        cnt += 1;
        int a;
        cin >> a;
        if (m[a]==0) {
            seq[a] = cnt;
        }
        m[a] += 1;
    }

    for(auto p : m) {
        v.push_back({p.first,p.second});
    }
    
    sort(v.begin(),v.end(),cmp);

    for(auto a : v) {
        for(int i=0; i<a.second; i++) {
            cout << a.first << ' ';
        }
    }
    return 0;
}