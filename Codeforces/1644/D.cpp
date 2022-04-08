#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
const long long MOD = 998244353;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        long long n, m, k, q;
        long long ans = 1;
        vector<pair<int, int> > opts;
        set<int> f, s;
        cin >> n >> m >> k >> q;

        for(int i = 0;i < q;i++)    {
            int t1, t2;
            cin >> t1 >> t2;
            opts.push_back(make_pair(t1, t2));
        }
        reverse(opts.begin(), opts.end());

        for(auto opt:opts)  {
            if(f.find(opt.first) != f.end() && s.find(opt.second) != s.end())    continue;

            f.insert(opt.first);
            s.insert(opt.second);
            ans *= k;
            ans %= MOD;

            if(f.size() == n || s.size() == m)  break;
        }

        cout << ans << endl;

    }
    return 0;

}

