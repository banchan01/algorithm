#include <bits/stdc++.h>
using namespace std;

int arr[200];
int main() {
    string s; cin >> s;
    for(char c : s) {
        arr[c]++;
    }
    int can = 2; string hol = "";
    for(int i=0; i<200; i++) {
        if(can==0) {
            cout << "I'm Sorry Hansoo" << '\n';
            return 0;
        }
        if(arr[i]%2==1) {
            can--;
            hol = char(i);
        }
    }

    string prev = "";
    for(int j=0; j<200; j++) {
        if(arr[j]<=0) continue;
        arr[j] /=2;
        for(int i=0; i<arr[j]; i++) {
            prev += char(j);
        }
    }

    string next = prev; reverse(next.begin(), next.end());
    cout << prev + hol + next << '\n';
    return 0;
}