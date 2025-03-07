#include <bits/stdc++.h>
using namespace std;

int n, cnt[26];
string s,result;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s;
        cnt[s[0] - 'a']++;
    }
    for(int i=0;i<26;i++) {
        if (cnt[i]>=5) {
            result += char(i+'a');
        }
    }
    if (!result.size()) {
        result = "PREDAJA";
    }

    cout << result;
}