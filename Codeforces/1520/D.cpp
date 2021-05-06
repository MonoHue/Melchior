#include <iostream>
#include <cstdio>
using namespace std;

const int eps = 220010;
int diffcnt[450000];

int main()  {
    int testcases;
    scanf("%d", &testcases);
    while(testcases --> 0)  {
        long long len, cnt = 0;
        scanf("%lld", &len);

        for(int i = 0;i < 450000;i++)   diffcnt[i] = 0;
        for(int i = 1;i <= len;i++) {
            int t;
            scanf("%d", &t);
            int diff = t - i + eps;
            cnt += diffcnt[diff];
            diffcnt[diff]++;
        }

        printf("%lld\n", cnt);
    }

    return 0;
}