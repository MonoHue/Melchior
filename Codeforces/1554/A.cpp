#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long nums[100010];

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        int n;
        long long ans = 1;
        cin >> n;
        for(int i = 0;i < n;i++)    cin >> nums[i];
        for(int i = 0;i < n - 1;i++)    ans = max(ans, nums[i] * nums[i + 1]);

        cout << ans << endl;

    }

    return 0;
}