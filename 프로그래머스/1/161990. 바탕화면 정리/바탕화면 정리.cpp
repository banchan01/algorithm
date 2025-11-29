#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int row = wallpaper.size();
    int col = wallpaper[0].length();
    int si=100,sj=100,ei=-100,ej=-100;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(wallpaper[i][j]=='#') {
                if(i<si) si = i;
                if(j<sj) sj = j;
                if(i>ei) ei = i;
                if(j>ej) ej = j;
            }
        }
    }
    answer.push_back(si);
    answer.push_back(sj);
    answer.push_back(ei+1);
    answer.push_back(ej+1);
    return answer;
}