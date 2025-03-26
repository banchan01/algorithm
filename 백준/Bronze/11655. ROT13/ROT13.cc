#include <bits/stdc++.h>
using namespace std;

string s;
string result;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin,s);
    for (char ch : s) {
        if (65<=ch && ch<=90) {
            if(int(ch)+13 > 90) result += 65 + ((int(ch)+13)-90)-1;
            else result += int(ch) + 13;
        }
        else if (97<=ch && ch<=122) {
            if(int(ch)+13 > 122) result += 97 + ((int(ch)+13)-122)-1;
            else result += int(ch) + 13;
        }
        else result += ch;
    }
    cout << result;
}