#include <bits/stdc++.h>
using namespace std;

string s;

string is_blc(string a) {
    stack<char> st;
    for(char c : a) {
        if(c=='(' || c=='[') {
            st.push(c);
        }
        if(c==')') {
            if(st.empty() || st.top()!='(') return "no";
            else st.pop();
        }

        if(c==']') {
            if(st.empty() || st.top()!='[') return "no";
            else st.pop();
        }
    }
    if(st.empty()) return "yes";
    else return "no";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(getline(cin,s)) {
        if (s == ".") return 0;
        cout << is_blc(s) << '\n';
    }
    return 0;
}