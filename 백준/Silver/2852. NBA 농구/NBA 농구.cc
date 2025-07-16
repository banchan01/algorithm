#include <bits/stdc++.h>
using namespace std;

int n,team,sc,prv,a=0,b=0,ret1=0,ret2=0;
string timi;

string to_t(int b) {
    string ret = "";
    string m = "00"+to_string(b/60);
    string s = "00"+to_string(b%60);
    return ret = m.substr(m.size()-2,2) + ":" + s.substr(s.size()-2,2);
}

int to_s(string& a) {
    return stoi(a.substr(0,2))*60 + stoi(a.substr(3,2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while(n--) {
        cin >> team >> timi;
        sc = to_s(timi);
        if(a>b) {
            ret1 += sc-prv;
        }
        if(a<b) {
            ret2 += sc-prv;
        }
        prv = sc;
        team==1 ? a++ : b++;
    }
    if(a>b) ret1 += 48*60 - sc;
    if(a<b) ret2 += 48*60 - sc;
    cout << to_t(ret1) << '\n' << to_t(ret2);    

    return 0;
}