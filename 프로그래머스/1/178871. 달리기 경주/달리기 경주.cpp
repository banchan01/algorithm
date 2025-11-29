#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string,int> rank;
    
    int n = players.size();
    for(int i=0; i<n; i++) {
        rank[players[i]] = i;
    }
    for(auto& c : callings) {
        int i = rank[c];
        int j = i-1;
        string front = players[j];
        // 딕셔너리 순서 바꾸기
        rank[c] = j;
        rank[front] = i;
        // 배열 순서 바꾸기
        players[j] = c;
        players[i] = front;
    }
    answer = players;
    return answer;
}