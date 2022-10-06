#include <iostream>
#include <map>

using namespace std;

const long long MOD = 1e9 + 7;

int len, l, r;
map<int, int> m;


int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        cin >> len;
        for (int i = 0; i < len; i++) {
            int t;
            cin >> t;
            m[t] = i;
        }

        l = min(m[0], m[1]);
        r = max(m[0], m[1]);

        long long ans = 1;
        for (int i = 2; i < len; i++) {
            if (l < m[i] && m[i] < r) {
                ans *= r - l + 1 - i;
                ans %= MOD;
            } else if (m[i] < l) l = m[i];
            else r = m[i];
        }

        cout << ans << endl;
    }

    return 0;
}