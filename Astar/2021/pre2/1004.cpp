#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, x = 0, rounds = 0, addPerRound = 0;

struct POINT{
    long long val;
    long long pre;
}nums[100010];

bool tryOneRound()  {
    rounds++;
    for(int i = 0;i < n && x < m;i++)   {
        x += nums[i].val;
        if(x < 0)   x = 0;
    }
    if(x >= m)  { cout << rounds << endl;return true; }
    return false;
}

int main()  {
    int testcase;scanf("%d", &testcase);while(testcase --> 0)    {
        x = 0;
        rounds = 0;
        addPerRound = 0;
        scanf("%lld%lld", &n, &m);
        scanf("%lld", &nums[0].val);
        nums[0].pre = 0;
        for(int i = 1;i < n;i++)    {
            scanf("%lld", &nums[i].val);
            nums[i].pre = nums[i - 1].pre + nums[i - 1].val;
        }
        nums[n].pre = nums[n - 1].pre + nums[n - 1].val;
        addPerRound = nums[n].pre;

        if(addPerRound <= 0)   {
            if(!tryOneRound())  tryOneRound();

            if(x < m)   cout << -1 << endl;

            continue;
        }

        bool doubleReset = false;
        tryOneRound();
        rounds++;
        for(int i = 0;i < n && x < m;i++)   {
            x += nums[i].val;
            if(x >= m)  { cout << rounds << endl; }
            if(x < 0)   { doubleReset = true;break; }
        }
        if(doubleReset) { cout << -1 << endl;continue;}

        long long peak = -10000;
        for(int i = 1;i <= n;i++)    peak = max(peak, nums[i].pre);

        long long diff = m - peak - x;
        if(diff < 0)    diff = 0;
        rounds += diff / addPerRound;
        x += addPerRound * (diff / addPerRound);
        while(x < m)    {
            tryOneRound();
        }

    }

    return 0;
}