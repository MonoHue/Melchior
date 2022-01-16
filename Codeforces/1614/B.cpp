#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> dt;

const int base = 500000;

int n;
int loc[200010];
dt nums[200010];

bool sortByFirst(dt a, dt b){
    return a.first > b.first;
};

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        long long ans = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nums[i].first;
            nums[i].second = i;
        }
        sort(nums, nums+n, sortByFirst);

        for(int i = 0;i < n;i++)    {
            int diff = i / 2 + 1;
            ans += 2ll * diff * nums[i].first;
            if(i % 2 == 1)  diff *= -1;
            loc[nums[i].second] = base + diff;
        }

        cout << ans << endl << base << " ";
        for(int i = 0;i < n;i++)    cout << loc[i] << " ";
        cout << endl;
    }

    return 0;
}