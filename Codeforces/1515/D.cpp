#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int color[200010][2];

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        int n, l, r;
        int ans = 0;
        cin >> n >> l >> r;
        for(int i = 0;i < l;i++)    {
            int t;
            cin >> t;
            color[t][0]++;
        }
        for(int i = 0;i < r;i++)    {
            int t;
            cin >> t;
            color[t][1]++;
        }

        int leftselfswap = 0, rightselfswap = 0;
        for(int i = 1;i <= n;i++)    {
            if(color[i][0] > 0 && color[i][1] > 0)  {
                int t = min(color[i][0], color[i][1]);
                color[i][0] -= t;
                color[i][1] -= t;
                r -= t;
                l -= t;
            }
            if(color[i][0] > 1 && l > r) {
                int maxchange = min((l - r) / 2, color[i][0] / 2);
                leftselfswap += max(0, color[i][0] / 2 - (l - r) / 2);
                ans += maxchange;
                l -= maxchange * 2;
                color[i][0] -= maxchange * 2;
            }
            if(color[i][1] > 1 && r > l) {
                int maxchange = min((r - l) / 2, color[i][1] / 2);
                rightselfswap += max(0, color[i][1] / 2 - (r - l) / 2);
                ans += maxchange;
                r -= maxchange * 2;
                color[i][1] -= maxchange * 2;
            }
            color[i][0] = 0; color[i][1] = 0;
        }

        int selfswap = min(leftselfswap, rightselfswap);
        ans += selfswap;
        l -= selfswap;
        r -= selfswap;
        ans += (l + r) / 2 + abs(l - r) / 2;

        cout << ans << endl;
    }

    return 0;
}