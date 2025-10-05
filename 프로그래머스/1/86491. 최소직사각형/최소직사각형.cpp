#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    // 둘 중 큰걸 첫번재 인덱스로
    for(auto& n : sizes) {
        if(n[1]>n[0]) {
            swap(n[0],n[1]);
        }
    }
    
    // 가로세로 max 찾기
    int w = 0;
    int h = 0;
    for(auto& a : sizes) {
        w = max(w, a[0]);
        h = max(h, a[1]);
    }
    answer = w*h;
    return answer;
}