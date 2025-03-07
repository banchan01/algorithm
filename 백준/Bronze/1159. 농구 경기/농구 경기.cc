#include <bits/stdc++.h>
using namespace std;

string name;
int n;
bool flag = false;
map<char,int> m;

int main()
{
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> name;
        m[name[0]] += 1;
        if (m[name[0]] >=5) {
            flag = true;
        }
    }
    if (flag) {
        for (auto& pair : m) {
            if(pair.second >= 5) {
                cout << pair.first;
            }
        }
    }
    else {
        cout << "PREDAJA";
    }

    return 0;
}