#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Data{
    long long val;
    long long num;
    long long accumNum;
    long long bSum;
    long long cSum;
}dat[200010];

int n, len;
long long ans = 0;

void update(int index, long long preB)    {
    long long tmpAns = 0, loc = 0;
    for(int i = 0;i < index;i++)    {
        tmpAns += dat[i].cSum + dat[i].bSum * (dat[index].accumNum - dat[index].num - dat[i].accumNum);
    }

    loc = preB / (-dat[index].val);
    ans = max(ans, loc * (loc + 1) / 2 * dat[index].val + loc * tmpAns);
    loc++;
    if(loc <= dat[index].accumNum)
        ans = max(ans, loc * (loc + 1) / 2 * dat[index].val + loc * tmpAns);
    loc = dat[index].accumNum;
    ans = max(ans, loc * (loc + 1) / 2 * dat[index].val + loc * tmpAns);
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- > 0) {
        scanf("%d%d", &n, &len);

        int tmp = 0;
        for(int i = 0;i < n;i++)    {
            scanf("%lld%lld", &dat[i].val, &dat[i].num);
            dat[i].bSum = dat[i].val * dat[i].num;
            dat[i].accumNum = tmp += dat[i].num;
            dat[i].cSum = dat[i].num * (dat[i].num + 1) / 2 * dat[i].val;
        }

        long long pre = 0;
        for(int i = 0;i < n;i++)    {
            long long newPre = pre + dat[i].bSum;
            if(pre >= 0 && newPre < 0 || i == n - 1)  update(i, pre);
            pre = newPre;
        }

        printf("%lld\n", ans);
    }

    return 0;
}