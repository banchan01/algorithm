#include <bits/stdc++.h>
using namespace std;


int t,n,result;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--) {
        result = 0;
        cin >> n;
        for(int i=5; i<=n; i*=5) {
            result += n/i;
        }
        cout << result<< '\n';
    }
    return 0;
}