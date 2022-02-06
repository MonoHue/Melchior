#include <iostream>
#include <vector>

using namespace std;

long long n, l, w;
long long nums[100010];
long long ans = 0;

int main() {
    cin >> n >> l >> w;
    for (int i = 0; i < n; i++) cin >> nums[i];
    nums[n] = l;

    long long last = 0;
    for(int i = 0;i <= n;i++)    {
        if(last == nums[i]) {
            last += w;
            continue;
        }

        if(nums[i] > last) {
            if ((nums[i] - last) % w == 0) ans += (nums[i] - last) / w;
            else ans += (nums[i] - last) / w + 1;
        }

        last = nums[i] + w;
    }

    cout << ans;

    return 0;
}