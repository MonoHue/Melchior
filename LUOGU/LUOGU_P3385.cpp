#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, cost;
};

int v, m, edgeCnt;
int dp[3000];
Edge es[6010];

void addEdge(int f, int t, int c) {
    es[edgeCnt].from = f;
    es[edgeCnt].to = t;
    es[edgeCnt].cost = c;
    edgeCnt++;
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while (testcases--) {
        scanf("%d%d", &v, &m);
        edgeCnt = 0;
        while(m--) {
            int f, t, w;
            scanf("%d%d%d", &f, &t, &w);
            if (w >= 0) {
                addEdge(f, t, w);
                addEdge(t, f, w);
            } else addEdge(f, t, w);
        }
        for(int i = 2;i <= v;i++)    {
            dp[i] = 1e9;
        }
        dp[1] = 0;

        bool flag = false;
        for(int round = 0;round < v;round++)    {
            for(int i = 0;i < edgeCnt;i++)  {
                if(dp[es[i].to] > dp[es[i].from] + es[i].cost && dp[es[i].from] + es[i].cost < 1e9 / 2)  {
                    dp[es[i].to] = dp[es[i].from] + es[i].cost;
                    if(round == v - 1)  flag = true;
                }
            }

        }
        if(flag)    printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}