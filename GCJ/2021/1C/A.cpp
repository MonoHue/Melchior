#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int max1, max2;
int num[200];

void pushin(int t)  {
    if(t > max1)    {
        max2 = max1;
        max1 = t;
    }
    else if (t > max2) {
        max2 = t;
    }
}

int main()  {
    int testcases;cin >> testcases;
    for(int curcase = 1;curcase <= testcases;curcase++)  {
        max1 = 0, max2 = 0;
        int n, k;
        cin >> n >> k;
        for(int i = 0;i < n;i++)    cin >> num[i];
        sort(num, num + n);

        if(num[0] != 1) {
            pushin(num[0] - 1);
        }
        for(int i = 0;i < n - 1;i++)   {
            if(num[i] + 1 == num[i + 1] || num[i] == num[i + 1])    pushin(0);
            else {
                pushin((num[i + 1] - num[i] - 2) / 2 + 1);
            }
        }
        if(num[n - 1] != k) {
            pushin(k - num[n - 1]);
        }

        int inclusive = 0;
        for(int i = 0;i < n - 1;i++)    {
            inclusive = max(num[i + 1] - num[i] - 1, inclusive);
        }

        printf("Case #%d: %f\n", curcase, max((max1 + max2), inclusive) * 1.0 / k);
    }
    return 0;
}