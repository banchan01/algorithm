#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 99999;
    
    for(int i=0; i<n-1; i++) {
        vector<bool> used(n-1,false);
        stack<int> A; stack<int> B;
        int a = wires[i][0]; int b = wires[i][1];
        used[i] = true;
        A.push(a); B.push(b);
        int num_A = 0;
        int num_B = 0;
        int ta=-1; int tb=-1;
        while(!A.empty() || !B.empty()) {
            if(!A.empty()) {
                ta = A.top(); A.pop(); num_A++;
            }
            else ta = -1;
            
            if(!B.empty()) {
                tb = B.top(); B.pop(); num_B++;
            }
            else tb = -1;
            
            for(int j=0; j<n-1; j++) {
                // A
                if(used[j] == false && ta != -1) {
                    int f = wires[j][0];
                    int s = wires[j][1];
                    if(ta == f) {
                        A.push(s);
                        used[j] = true;
                    }
                    if(ta == s) {
                        A.push(f);
                        used[j] = true;
                    }
                }
                // B
                if(used[j] == false && tb != -1) {
                    int f = wires[j][0];
                    int s = wires[j][1];
                    if(tb == f) {
                        B.push(s);
                        used[j] = true;
                    }
                    if(tb == s) {
                        B.push(f);
                        used[j] = true;
                    }
                }
            }
        }
        answer = min(answer, abs(num_A - num_B));
    }
    return answer;
}