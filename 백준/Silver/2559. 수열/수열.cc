#include <bits/stdc++.h>
using namespace std;

int n,k, maxi=0,result=0;
int arr[100005];
int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        result += temp;
        arr[i] = temp;
    }
    for(int i=0; i<n;i++) {
        if(i+k>n) break;
        int tmp =0;
        for(int j=i; j<i+k;j++) {
            //cout << arr[j] << ' ';
            tmp += arr[j];
        }
        if (maxi<tmp) maxi = tmp;
        //cout << '\n';
    }
    if (k!=n) result = maxi;
    cout << result;
    return 0;
}