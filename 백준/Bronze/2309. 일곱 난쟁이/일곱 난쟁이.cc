#include <bits/stdc++.h>
using namespace std;

int arr[9];
int n=9, k=7;
void combi(int start, vector<int> &b) {
    if(b.size()==k) {
        int sum =0;
        for(int idx : b) {
            sum += arr[idx];
        }
        if(sum==100) {
            for(int idx : b) {
                cout << arr[idx] << '\n';
            }
            exit(0);
        }
        return;
    }
    for(int i=start+1; i<n; i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main() {
    for(int i=0; i<9; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+9);
    
    vector<int> b;
    combi(-1, b);
    return 0;
} 