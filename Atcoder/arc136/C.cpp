#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int n;
long long cnt = 0;
int nums[200010];

void solve(int start, int end, int accum) {
    if (end < start) {
        int minVal = min(*min_element(nums + start, nums + n),
                         *min_element(nums, nums + start));
        int s = start;
        cnt += minVal - accum;
        for (int i = start + 1; i < n; i++) {
            if (nums[i] == minVal) {
                if (s != i) solve(s, i, minVal);
                s = i + 1;
            }
        }
        for (int i = 0; i < end; i++) {
            if (nums[i] == minVal) {
                if (s != i) solve(s, i, minVal);
                s = i + 1;
            }
        }
    } else {
        int minVal = *min_element(nums + start, nums + end);
        int s = start;
        cnt += minVal - accum;
        vector<int> pend;
        
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    solve(0, n, 0);

    printf("%d", cnt);

    return 0;
}