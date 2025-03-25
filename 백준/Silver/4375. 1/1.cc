#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    while(scanf("%d", &n) != EOF) {
        int i=1;
        long long tmp_result = 1;
        while(true) {
            if (tmp_result % n ==0) {
                cout << i << '\n';
                break;
            }else {
                i++;
                tmp_result = (tmp_result * 10) + 1;
                tmp_result %= n;
            }
            
        }
    }
    return 0;
}