#include <bits/stdc++.h>
using namespace std;
int alpha[26];

int main() {
    string s;
    cin >> s;
    for (char c : s) {
        alpha[c-'a'] += 1;
    }
    for(int n : alpha) {
        cout << n << ' ';
    }
    return 0;
}