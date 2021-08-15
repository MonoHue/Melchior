#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double nums[200010];

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        int n;
        scanf("%d", &n);
        for(int i = 0;i < n;i++)    scanf("%lf", &nums[i]);

        double tmax = -1000000010;
        double sum = 0;
        for(int i = 0;i < n;i++)    {
            sum += nums[i];
            tmax = max(tmax, nums[i]);
        }

        printf("%.9f\n", tmax + (sum - tmax) / (n - 1));

    }

    return 0;
}