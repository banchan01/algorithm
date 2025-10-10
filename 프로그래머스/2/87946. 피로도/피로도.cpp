#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int tmp = k;
    int answer = -1;
    int t_answer = 0;
    int length = dungeons.size();
    // 순서 vector에 넣기
    vector<int> order;
    for(int i=0; i<length; i++) {
        order.push_back(i);
    }
    // 순열 돌리기
    do {
        tmp = k;
        t_answer = 0;
        for(auto& idx : order) {
            if(tmp<dungeons[idx][0]) break;
            tmp -= dungeons[idx][1];
            t_answer += 1;
        }
        answer = max(answer, t_answer);
    } while(next_permutation(order.begin(), order.end()));
    
    return answer;
}