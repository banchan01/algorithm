#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1; i<=yellow; i++) {
        int na = yellow%i;
        if(na == 0) {
            int mock = yellow/i;
            int area = (i+2) * (mock+2);
            if(area - yellow == brown) {
                answer.push_back(mock+2);
                answer.push_back(i+2);
                break;
            }
        }
    }
    sort(answer.begin(), answer.end(), greater<int>());
    
    return answer;
}