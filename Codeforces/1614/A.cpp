#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long n, l, r, k;
long long nums[110];

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        int cnt = 0;
        cin >> n >> l >> r >> k;
        for(int i = 0;i < n;i++)    cin >> nums[i];
        sort(nums, nums + n);

        for(int i = 0;i < n &&k > 0&& nums[i] <= r;i++) {
            if(nums[i] < l) continue;

            k -= nums[i];
            if(k >= 0)cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}