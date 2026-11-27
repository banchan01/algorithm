#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int arr[n] = {};
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int real[n-k+1] = {};
    for(int i= 0; i<k; i++) {
        real[0] += arr[i];
    }
    for(int idx=1; idx<=n-k; idx++) {
        real[idx] = real[idx-1] - arr[idx-1] + arr[idx+k-1];
    }
    cout << *max_element(real, real+n-k+1);
    return 0;
}