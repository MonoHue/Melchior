#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n, k;
int out[200010], father[200010], len[200010];
set<int> open;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= n; i++) len[i] = 1;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        auto lb = open.lower_bound(t);

        if (lb == open.end()) {
            if (k == 1) {
                out[t] = i;
            } else open.insert(t);

            continue;
        }

        int val = *lb;
        open.erase(lb);
        father[t] = val;
        len[t] = len[val] + 1;

        if (len[t] == k) {
            out[t] = i;
            while (father[t] != t) {
                t = father[t];
                out[t] = i;
            }
        } else open.insert(t);
    }

    for (int i = 1; i <= n; i++)
        if (out[i] != 0)
            cout << out[i] << endl;
        else
            cout << -1 << endl;

    return 0;
}