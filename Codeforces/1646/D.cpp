#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n;
long long sum = 0, cnt = 0;
bool visited[200010];
bool isGood[200010];
long long val[200010];
vector<int> process;
map<int, vector<int> > m;

bool checkNeighbourTrue(int u) {
    for (auto v: m[u]) {
        if (isGood[v]) return false;
    }
    return true;
}

void setGood(int u) {
    cnt++;
    val[u] = m[u].size();
    sum += val[u];
    isGood[u];
}

void setBad(int u) {
    val[u] = 1;
    sum += val[u];
}

void update(vector<int> &vec, bool chosen) {
    set<int> ret;

    sort(vec.begin(), vec.end(),
         [](int a, int b) -> bool {
             return m[a].size() < m[b].size();
         });

    for (auto u: vec) {
        if (visited[u]) continue;
        visited[u] = true;
        if (chosen) {
            if (!checkNeighbourTrue(u)) {
                setGood(u);
            } else {
                setBad(u);
            }
        } else {
            setBad(u);
        }

        for (auto v: m[u]) {
            if (!visited[v]) ret.insert(v);
        }
    }

    vec = vector<int>(ret.begin(), ret.end());
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        m[u - 1].push_back(v - 1);
        m[v - 1].push_back(u - 1);
    }
    for (const auto &key: m) {
        if (key.second.size() == 1) process.push_back(key.first);
    }

    if (n == 2) {
        printf("2 2\n1 1\n");
        return 0;
    }

    bool flag = true;
    while (!process.empty()) {
        update(process, flag);
        flag = !flag;
    }

    printf("%lld %lld\n", cnt, sum);
    for (int i = 0; i < n; i++) printf("%lld ", val[i]);

    return 0;
}