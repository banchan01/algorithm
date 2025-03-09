#include <bits/stdc++.h>
using namespace std;

int n,k,tmp;
int arr[100005];
int result = -10000005;
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        arr[i+1] = arr[i] + tmp;
    }
    for(int i=k; i<=n; i++) {
        result = max(result, arr[i]-arr[i-k]);
    }
    cout << result;
    return 0;
}