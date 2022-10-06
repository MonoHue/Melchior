#include <iostream>
#include <algorithm>

using namespace std;

int nums[200010];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int n;
        long long ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &nums[i]);

        bool start = false;
        for (int i = 0; i < n; i++) {
            if (!start && nums[i] > 0) {
                start = true;
            }
            if (start) {
                ans += nums[i];
                if (nums[i] == 0 && i != n - 1) ans++;
            }
        }
        ans -= nums[n - 1];

        cout << ans << endl;
    }

    return 0;
}