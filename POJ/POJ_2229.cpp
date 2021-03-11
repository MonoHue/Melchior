/*
 * dp[i] = dp[i - 1]    (i is odd)
 * dp[i] = dp[i - 1] + dp[i / 2]    (i is even)
 *
 * 1.   When i is odd, attach '1' to each expression. Thus, the cases remain the same.
 * 2.   When i is even,
 *  a)  When a expression does not have '1', we divide each number with 2, and the quantity of cases is dp[i / 2].
 *  b)  Else, if a expression has '1', attach '1' to each expression. the quantity of cases is dp[i - 1].
 */


#include <iostream>
#define MOD 1000000000
using namespace std;

int n;
int dp[1000010];

int main()  {
    cin >> n;
    dp[0] = 0;dp[1] = 1;

    for(int i = 2;i <= n;i++)   {
        if(i & 1)   dp[i] = dp[i - 1];
        else {
            dp[i] = dp[i - 1] + dp[i / 2];
            dp[i] %= MOD;
        }
    }

    cout << dp[n];

    return 0;
}