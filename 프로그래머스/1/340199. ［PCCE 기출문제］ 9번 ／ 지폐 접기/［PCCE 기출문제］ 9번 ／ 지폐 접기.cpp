#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int answer = 0;
int l_wallet=0, s_wallet=0, l_bill=0, s_bill=0;
bool flag = false;
void check_wallet(vector<int>& wallet) {
    if (wallet[0] > wallet[1]) {
        l_wallet = wallet[0]; 
        s_wallet = wallet[1];
    } 
    else {
        l_wallet = wallet[1];
        s_wallet = wallet[0];
    } 
}

void check_bill(vector<int>& bill) {
    if (bill[0] > bill[1]) {
        l_bill = bill[0]; 
        s_bill = bill[1];
    } 
    else {
        l_bill = bill[1]; 
        s_bill = bill[0];   
    }
}

int solution(vector<int> wallet, vector<int> bill) {
    // wallet 큰값, 작은값 저장
    check_wallet(wallet);
    // bill 큰값, 작은값 저장
    check_bill(bill);
    
    if (l_wallet >= l_bill && s_wallet >= s_bill) {
        return answer;
    }
    else {
        while(true) {
            l_bill /= 2;
            answer++;
            if(s_bill>l_bill) {
                int tmp = l_bill;
                l_bill = s_bill;
                s_bill = tmp;
            }
            if (l_wallet >= l_bill && s_wallet >= s_bill) break;
        }
    }
    
    return answer;
}