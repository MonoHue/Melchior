#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>

using namespace std;

int n, x;
int nums[5010];
int maxi[5010];

int main() {
    int testcases;
    scanf("%d" , &testcases);
    while (testcases--) {
        scanf("%d%d" , &n, &x);
        for(int i = 0;i < n;i++)
            scanf("%d" , &nums[i]);

        maxi[0] = 0;
        for(int i = 1;i <= n;i++)   {
            int tmp = 0;
            for(int j = 0;j < i;j++)    tmp += nums[j];
            maxi[i] = tmp;
            for(int j = 1;j <= n - i;j++)   {
                tmp = tmp - nums[j - 1] + nums[i + j - 1];
                maxi[i] = max(tmp, maxi[i]);
            }
        }

        printf("%d ", max(0, *max_element(maxi + 1, maxi+n + 1)));
        for(int i = 1;i <= n;i++)   {
            for(int j = i;j <= n;j++)
                maxi[j] += x;
            printf("%d ", max(0, *max_element(maxi + 1, maxi+n + 1)));
        }
        printf("\n");

    }

    return 0;
}