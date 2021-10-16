#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long sum = 0;
long long nums[200010];
long long def, atk;

int search(int l, int r, long long val)  {
    if(r - l == 1)  return r;

    int mid = (l + r) / 2;
    if(nums[mid] >= val) return search(l, mid, val);
    return search(mid, r, val);
}

int main()  {
    scanf("%d", &n);
    for(int i = 0;i < n;i++)    {
        scanf("%lld", &nums[i]);
        sum += nums[i];
    }
    sort(nums, nums + n);
    int testcases;cin >> testcases;while(testcases --> 0)   {
        long long ans = 0;
        scanf("%lld%lld", &def, &atk);
        int pos;
        if(nums[n - 1] < def)   pos = n;
        else if(nums[0] > def)  pos = 0;
        else    pos = search(0, n, def);
        if(pos == n)    {
            pos--;
            ans += def - nums[pos];
            ans += max(atk + nums[pos] - sum, 0ll);
        }
        else if(pos == 0 || nums[pos] == def)   {
            ans += max(atk + nums[pos] - sum, 0ll);
        }
        else {
            long long less = 0, big = 0;
            big += max(atk + nums[pos] - sum, 0ll);
            pos--;
            less += max(atk + nums[pos] - sum, 0ll);
            less += def - nums[pos];

            ans = min(less, big);
        }

        printf("%lld\n", ans);
    }

    return 0;
}