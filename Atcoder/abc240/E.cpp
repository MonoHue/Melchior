#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int cnt = 1;
bool visited[200010];
pair<int, int> ans[200010];
set<int> edge[200010];

pair<int, int> dfs(int u)    {
    visited[u] = true;
    if(edge[u].size() == 1 && u != 1) {
        ans[u] = make_pair(cnt, cnt);
        cnt++;
        return ans[u];
    }

    int l = 1e9, r = 1e9;
    for(auto v:edge[u]) {
        if(visited[v])  continue;

        auto t = dfs(v);
        if(l == 1e9)    {l = t.first; r = t.second;}
        else {
            l = min(l, t.first);
            r = max(r, t.second);
        }
    }
    return ans[u] = make_pair(l, r);
}

int main()  {
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n - 1;i++)    {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].insert(v);
        edge[v].insert(u);
    }

    ans[1] = dfs(1);

    for(int i = 1;i <= n;i++)    {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}