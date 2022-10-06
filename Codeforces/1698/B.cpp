#include <cstdio>
#include <iostream>
using namespace std;

long long nums[200010];

int main() {
    int testcases;cin >> testcases;
    while (testcases --> 0) {
        int n, k;
        scanf("%d%d", &n, &k);

        for(int i = 0;i < n;i++)
            scanf("%lld", &nums[i]);

        int ans = 0;
        for(int i = 1;i < n - 1;i++)
            if(nums[i] > nums[i - 1] + nums[i + 1])
                ans++;

        if(k == 1)  ans = (n - 1) / 2;

        cout << ans << endl;
    }

    return 0;
}