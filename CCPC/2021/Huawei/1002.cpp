#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[100010], b[100010], c[100010];

bool check(int k)    {
    int b = c[0] - a[0] * k;
    for(int i = b - 10;i <= b + 10;i++) {
        bool ok = true;
        for(int j = 0;j < n;j++)    {
            int changed = k * a[j] + i;
            if(!(-10 <= c[j] - changed && c[j] - changed <= 10))    {
                ok = false;
                break;
            }
        }
        if(ok)  return true;
    }
    return false;
}

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        scanf("%d", &n);
        bool isFirst = false;
        for(int i = 0;i < n;i++) scanf("%d", &a[i]);
        for(int i = 0;i < n;i++) scanf("%d", &b[i]);
        for(int i = 0;i < n;i++) scanf("%d", &c[i]);

        sort(a, a + n);
        sort(b, b + n);
        sort(c, c + n);
        int k = (c[n - 1] - c[0]) /(a[n - 1]- a[0]);
        k = max(0, k);

        for(int i = max(0, k - 20);i <= k + 20;i++)
            if(check(i)) { isFirst = true;break; }

        if(isFirst) printf("1\n");
        else printf("2\n");
    }

    return 0;
}
