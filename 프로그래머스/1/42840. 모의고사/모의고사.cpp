#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int f[5] = {1,2,3,4,5};
    int s[8] = {2,1,2,3,2,4,2,5};
    int t[10] = {3,3,1,1,2,2,4,4,5,5};
    int first = 0, second = 0, third = 0;
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == f[i%5]) {
            first += 1;
        }
        if(answers[i] == s[i%8]) {
            second += 1;
        }
        if(answers[i] == t[i%10]) {
            third += 1;
        }
    }
    int score = max({first, second, third});
    if(score == first) answer.push_back(1);
    if(score == second) answer.push_back(2);
    if(score == third) answer.push_back(3);
    return answer;
}