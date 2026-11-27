#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string ptn; cin >> ptn;
    string l,r;
    int pos = ptn.find('*');
    l = ptn.substr(0,pos); r = ptn.substr(pos+1);
 
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        if(l.size() + r.size() > s.size()) cout << "NE" << '\n';
        else {
            if(s.substr(0,l.size()) == l && s.substr(s.size()- r.size())==r) {
                cout << "DA" << '\n';
            } else cout << "NE" << '\n';
        }
    }
    return 0;
}