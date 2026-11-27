#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n; int ret =0;
    for(int i=0; i<n; i++) {
        stack<int> st;
        string s; cin >>s;
        for(char c : s) {
            if(st.size() && st.top()==c) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        if(st.empty()) ret++;
    }
    cout << ret << '\n';
    return 0;
}