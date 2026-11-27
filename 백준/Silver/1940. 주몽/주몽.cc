#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m; cin >> n >> m;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        arr[a]++;
    }
    int ret=0;
    for(int i=0; i<100005; i++) {
        if(arr[i]==1 && m-i >=0 && m-i <100005 && i != m-i && arr[m-i]==1) {
            ret++;
            arr[i] =0; arr[m-i]=0;
        }
    }
    cout << ret << '\n';
    return 0;
}