#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;

ll go(ll a, ll b) {
    if(b==1) {
        return a%c;
    }
    ll tmp = go(a,b/2) % c;
    if(b%2==1) {
        return tmp%c * tmp%c * a%c;
    }
    return tmp%c * tmp%c;
}


int main() {
    cin >> a >> b >> c;
    cout << go(a,b) << '\n';
    return 0;
}