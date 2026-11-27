#include <bits/stdc++.h>
using namespace std;

int same(string s1, string s2) {
    reverse(s1.begin(), s1.end());
    if(s1==s2) {
        return 1;
    } else return 0;
}

int main() {
    string s;
    cin >> s;
    int idx = s.size()/2;
    if(s.size()%2==0) {
        string s1 = s.substr(0,idx);
        string s2 = s.substr(idx,s.size());
        cout << same(s1,s2);
    } else {
        string s1 = s.substr(0,idx);
        string s2 = s.substr(idx+1, s.size());
        cout << same(s1,s2);
    }
    return 0;
}