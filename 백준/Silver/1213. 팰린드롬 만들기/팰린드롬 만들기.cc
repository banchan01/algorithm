#include <bits/stdc++.h>
using namespace std;

string name;
map<char,int> mp;
int odd_cnt =0;
string center = "";
string half_result = "", result;
int main() {
    cin >> name;
    for (char ch : name) {
        mp[ch]++;
    }
    // for (auto pair : mp) {
    //     mp[pair.first] /= 2;
    // }
    for (auto pair : mp) {
        if (pair.second%2 != 0) odd_cnt++;
    }
    if (odd_cnt>1) {
            cout << "I'm Sorry Hansoo" << '\n';
            return 0;
    }
    for (auto pair : mp) {
        if (pair.second%2 != 0) {
            center = pair.first;
            mp[pair.first]--;
        } 
    }
    for (auto pair : mp) {
        mp[pair.first] /= 2;
    }
    for (auto pair : mp) {
        for(int i=0; i<pair.second; i++) {
            half_result += pair.first;
        }
    }
    string reversed_result = half_result;
    reverse(reversed_result.begin(),reversed_result.end());
    result = half_result + center + reversed_result;
    cout << result << '\n';
}