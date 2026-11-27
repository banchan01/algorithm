#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    getline(cin, s);
    for(char c : s) {
        if(c>=65 && c<=90) {
            int a = c+13;
            if(a>90) {
                a-=26;
            }
            cout << char(a);
        } else if(c>=97 && c<=122) {
            int b = c+13;
            if(b>122) {
                b-=26;
            }
            cout << char(b);
        } else {
            cout << c;
        }
    }
    return 0;
}