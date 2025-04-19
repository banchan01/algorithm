#include <iostream>
#include <vector>
using namespace std;

int n,k;
int main() {
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i=1; i<=n; i++) {
        for (int j=0; j<=min(i,k); j++) {
            if (i==j | j==0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1]%10007 + dp[i-1][j]%10007;
        }
    }

    cout << dp[n][k]%10007;
}