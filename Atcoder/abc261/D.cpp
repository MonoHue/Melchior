#include <iostream>
#include <map>

using namespace std;

int n, m;
long long x[5010];
long long dp[2][5010];

map<int, long long> y;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    for (int i = 0; i < m; i++) {
        int tc;
        long long ty;
        cin >> tc >> ty;
        y[tc] = ty;
    }

    for (int i = 1; i <= n; i++) {
        int last = (i - 1) % 2, now = i % 2;
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                for (int k = 0; k < i; k++)
                    dp[now][j] = max(dp[now][j], dp[last][k]);
            } else
                dp[now][j] = dp[last][j - 1] + x[i - 1] + y[j];
        }
    }

    long long maxi = -1;
    for (int i = 0; i <= n; i++)
        maxi = max(maxi, dp[n % 2][i]);

    cout << maxi << endl;

    return 0;
}