#include <bits/stdc++.h>
using namespace std;

int maxi =0;
int n,m,ingre, result=0;
int arr[300005];
int main() {
    cin >> n >> m;
    for(int i =1; i<=n; i++) {
        cin >> ingre;
        if (ingre>maxi) {
            maxi = ingre;
        }
        arr[ingre]++;
    }
    if(m > 200000) {
        cout << result;
        return 0;
    }
    for(int i =0; i<m; i++) {
        //cout << arr[i] << ' ';
        
        if (m%2==0 && i==m/2) continue;

        if (arr[i]==1 && arr[m-i]==1) {
            //cout << i << ' ' <<m-i << '\n';
            result++;
        }
    }
    cout << result/2;
    return 0;
}
