#include <bits/stdc++.h>
using namespace std;

int n;
string pattern;

string is_pattern(const string &s, string &pattern)
{
    bool flag = true;
    string result = "DA";
    string pre, end;
    for(char& ch : pattern) {
        if (ch=='*') {
            flag = false;
            continue;
        }
        if(flag) pre += ch;
        else end += ch;
    }
    /*
    ex) pattern : a*a , file : a 
    인 경우들 걸러주기
    */
    if (s.length()<pattern.length()-1) {
        result = "NE";
        return result;
    }
    /*
    앞자리 끼리 검사
    */
    for(int i=0; i<pre.length(); i++) {
        if(s[i] != pre[i]) result = "NE";
    }
    /*
    뒷뒷자리 끼리 검사
    */
    int diff = s.length()-end.length();
    for(int i = diff; i<s.length(); i++) {
        if(s[i] != end[i-diff]) result = "NE";
    }
    return result;
}


int main()
{
    cin >> n;
    cin >> pattern;
    
    for(int i=0;i<n;i++)
    {
        string file;
        cin >> file;
        cout << is_pattern(file,pattern)<< '\n';
    }
}