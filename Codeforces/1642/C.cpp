#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        long long n, x;
        map<long long, int> m;

        scanf("%lld%lld", &n, &x);
        for (int i = 0; i < n; i++) {
            long long t;
            scanf("%lld", &t);
            m[t]++;
        }

        int ans1 = 0;
        map<long long, int> tmp = m;
        for (auto key: tmp) {
            if (key.second == 0) continue;
            ans1 += max(key.second - tmp[x * key.first], 0);
            tmp[x * key.first] = max(tmp[x * key.first] - key.second, 0);
            key.second = max(key.second - tmp[x * key.first], 0);
        }

        cout << ans1 << endl;
    }
    return 0;

}

