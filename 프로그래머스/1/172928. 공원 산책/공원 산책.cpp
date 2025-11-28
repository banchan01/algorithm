#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int row = park.size();
    int col = park[1].length();
    char arr[row][col];
    // 2차원 배열에 넣기, si/sj 는 시작점 좌표
    int i=0 ,j=0, sj=0,si=0;
    for(auto pk : park) {
        for(char c : pk) {
            arr[i][j++] = c;   
            if(c=='S') {
                si=i;
                sj=j-1;
            }
        }
        i++;
        j=0;
    }

    // route수행
    int ci=si, cj=sj;
    bool flag = true;
    int tmp =0;
    for(auto r : routes) {
        cout << ci << ' ' << cj << '\n';
        char dir = r[0];
        int distance = r[2] - '0';
        switch (dir) {
            case 'E' :
                flag = true;
                tmp = cj;
                for(int i=1; i<=distance; i++) {
                    tmp+=1;
                    if(arr[ci][tmp] == 'X' || tmp>=col) {
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cj += distance;   
                }
                break;
            case 'W':
                flag = true;
                tmp = cj;
                for(int i=1; i<=distance; i++) {
                    tmp-=1;
                    if(arr[ci][tmp] == 'X' || tmp<0) {
                        flag = false;
                        break;
                    }
                }
                if(flag){
                 cj -= distance;   
                }
                break;
            case 'S':
                flag = true;
                tmp = ci;
                for(int i=1; i<=distance; i++) {
                    tmp+=1;
                    if(arr[tmp][cj] == 'X' || tmp>=row) {
                        flag = false;
                        break;
                    }
                }
                if(flag){
                 ci += distance;   
                }
                break;
            case 'N':
                flag = true;
                tmp = ci;
                for(int i=1; i<=distance; i++) {
                    tmp-=1;
                    if(arr[tmp][cj] == 'X' || tmp<0) {
                        flag = false;
                        break;
                    }
                }
                if(flag){
                 ci -= distance;   
                }
                break;
            default:
                break;
        }
    }
    answer.push_back(ci);
    answer.push_back(cj);
    return answer;
}