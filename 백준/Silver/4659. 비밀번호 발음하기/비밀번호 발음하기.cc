#include <bits/stdc++.h>
using namespace std;

string tc;
int mo,ja,cnt=0;

bool rule(string n) {
    // 1. 모음 하나 포함
    cnt = 0;
    for(char c : n) {
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
            cnt++;
            break;
        }
    }
    // 2. 모음/자음 3개 연속x
    mo = 0; ja =0 ;
    for(char c : n) {
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
            mo++;
            ja=0;
        }
        else {
            mo =0;
            ja++;
        }
        if(ja==3 || mo ==3) return false;
    }
    cnt++;

    // 3. 같은 글자 연속x (ee,oo제외)
    for(int i=0; i<n.size()-1; i++) {
        if(n[i] == n[i+1]) {
            if (n[i] == 'e' || n[i] == 'o') continue;
            return false;
        }
    }
    cnt++;
    if(cnt==3) return true;
    else return false;
}

int main() {
    while(cin >> tc) {
        if (tc == "end") return 0;
        if(rule(tc)) cout << "<" << tc << ">" << " is acceptable." << '\n';
        else cout << "<" << tc << ">" << " is not acceptable." << '\n';
    }
    return 0;
}