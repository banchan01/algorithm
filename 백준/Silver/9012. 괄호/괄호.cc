#include <bits/stdc++.h>
using namespace std;

int t;
string ps;
stack<char> st;

string VPS(string a) {
    st = stack<char>();
    for (auto c : a) {
        if(c=='(') {
            st.push(c);
        }
        else {
            if(st.size()) {
                st.pop();
            }
            else return "NO";
        }
    }
    if(st.size()) return "NO";
    else return "YES";
}

int main() {
    cin >> t;
    while(t--) {
        cin >> ps;
        cout << VPS(ps) << '\n';
    }
    return 0;
}