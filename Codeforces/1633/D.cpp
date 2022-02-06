#include <iostream>
#include <vector>

using namespace std;

int n, k;
int nums[1010];
int cost[1010];
int costSheet[1010];
int gain[1010];
long long dp[1000010];

void make_sheet()   {
    for(int i = 0;i < 1010;i++)    costSheet[i] = 114514;
    costSheet[1] = 0;
    for(int i = 1;i < 1010;i++) {
        for(int j = i;j >= 1 && i + i / j < 1010;j--) {
            costSheet[i + i / j] = min(costSheet[i + i / j], costSheet[i] + 1);
        }
    }
}

int main()  {
    make_sheet();
    int testcase;cin >> testcase;
    while (testcase-->0)    {
        cin >> n >> k;
        for(int i = 0;i < n;i++)    cin >> nums[i];
        for(int i = 0;i < n;i++)    cin >> gain[i];
        for(int i = 0;i < n;i++)    cost[i] = costSheet[nums[i]];

        k = min(k, 20000);
        for(int i = 0;i <= k;i++)    dp[i] = 0;
        for(int i = 0;i < n;i++)    {
            for(int j = k;j >= cost[i];j--) {
                dp[j] = max(dp[j], dp[j - cost[i]] + gain[i]);
            }
        }

        cout << dp[k] << endl;
    }

    return 0;
}