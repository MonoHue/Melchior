#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
long long nums[100010];
struct {
    long long sum;
    int cnt;
}dp[100010][2];

double getAverage(int loc, int type)  {
    if(dp[loc][type].cnt == 0)  return 0.0;
    else return dp[loc][type].sum * 1.0 / dp[loc][type].cnt;
}

int main()  {
    cin >> n;
    for(int i = 0;i < n;i++)    cin >> nums[i];
    dp[0][1].sum = nums[0];dp[0][1].cnt = 1;
    dp[0][0].sum = 0;dp[0][0].cnt = 0;
    for(int i = 1;i < n;i++)    {
        dp[i][0] = dp[i - 1][1];
        if(getAverage(i-1,0) > getAverage(i-1, 1))  {
            dp[i][1] = dp[i-1][0];
            dp[i][1].cnt++;dp[i][1].sum+=nums[i];
        }
        else{
            dp[i][1] = dp[i-1][1];
            dp[i][1].cnt++;dp[i][1].sum+=nums[i];
        }
    }

    cout << getAverage(n-1,0) << endl;
    cout << getAverage(n-1,1) << endl;

    return 0;
}

