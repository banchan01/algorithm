#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    map<string, string> name;
    map<string, string> number;
    for(int i=1; i<=n; i++) {
        string s; cin >> s;
        name[s] = to_string(i);
        number[to_string(i)] = s;
    }
    for(int j=0; j<m; j++) {
        string q; cin >> q;
        if(name.count(q)) cout << name[q] << '\n';
        else if(number.count(q)) cout << number[q] << '\n';
    }
    return 0;
}