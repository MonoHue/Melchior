#include <cstdio>
#include <iostream>

using namespace std;

const int INF = 1e9 + 1919810;
int n, m;
long long dp[310][310], edge[310][310];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++) {
            dp[i][j] = INF;
            edge[i][j] = INF;
        }
    while (m--) {
        int u, v;
        long long w;
        scanf("%d%d%lld", &u, &v, &w);
        dp[u][v] = w;
        edge[u][v] = w;
        dp[v][u] = w;
        edge[v][u] = w;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (edge[i][j] == INF) continue;

            bool selected = false, single = true;
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j || dp[i][k] == INF || dp[k][j] == INF) continue;
                single = false;
                if (edge[i][j] > dp[i][k] + dp[k][j]) selected = true;
            }
            if (!single && selected) {
                cout << i << j << endl;
                cnt++;
            }
        }

    printf("%d", cnt);

    return 0;
}