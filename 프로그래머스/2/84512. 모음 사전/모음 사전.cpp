#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int answer = 0;
int cnt = -1;
string vowel = "AEIOU";
string target = "";
bool found = false;


void DFS(string cur) {
    cnt++;
    
    if(cur == target) {
        answer = cnt;
        return;
    }
    if(cur.length() >= 5) return;
    for(int i=0; i<5; i++) {
        DFS(cur+vowel[i]);
    }
}

int solution(string word) {
    target = word;
    DFS("");    
    
    return answer;
}