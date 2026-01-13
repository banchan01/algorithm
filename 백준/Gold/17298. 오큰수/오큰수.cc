#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int result[1000005];
stack<int> st;

int main() {
    memset(result,-1,sizeof(result));
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        while(!st.empty() && a[st.top()] < a[i]) {
            result[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i=0; i<n; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}