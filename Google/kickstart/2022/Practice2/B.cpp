#include <iostream>

using namespace std;

int main()  {
    int testcases;cin >> testcases;
    for(int testcase = 1;testcase <= testcases;testcase++)  {
        long long l, r, ans = 0;
        cin >> l >> r;
        for(int i = 1;i <= min(l, r);i++)
            ans += i;
        cout << "Case #" << testcase << ": " << ans << endl;
    }

    return 0;
}