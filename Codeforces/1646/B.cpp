#include <iostream>
#include <algorithm>

using namespace std;

int n;
int nums[200010];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> nums[i];
        sort(nums, nums + n);

        long long diff = 1ll * nums[n - 1] - nums[0] - nums[1];
        int sLoc = 2, lLoc = n - 2;
        while (diff <= 0 && sLoc < lLoc) {
            diff += nums[lLoc--] - nums[sLoc++];
        }

        if(diff > 0)    cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}