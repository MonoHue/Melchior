#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int n;
long long dp[1000010][11];

int main()  {
    cin >> n;
    for(int i = 1;i <= 9;i++)   dp[1][i] = 1;
    for(int i = 1;i <= n;i++)  {
        for(int j = 1;j <= 9;j++)   {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
            dp[i + 1][j-1] += dp[i][j];
            dp[i + 1][j-1] %= MOD;
            dp[i + 1][j+1] += dp[i][j];
            dp[i + 1][j+1] %= MOD;
        }
    }

    long long ans = 0;
    for(int i = 1;i <= 9;i++) { ans += dp[n][i];ans %= MOD; }

    cout << ans << endl;

    return 0;
}