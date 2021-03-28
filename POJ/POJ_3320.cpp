#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#define RANGE 1000000
using namespace std;

int n;
int nums[RANGE];
set<int>    pts;
multiset<int>   ownpts;

int solve() {
    int l = 0, r = 0, ans = 0;

    while(r < n)    {
        while(ownpts.size() != pts.size()) {
            r++, ans++;

        }
    }

    return ans;
}

int main()  {
    cin >> n;

    for(int i = 0;i < n;i++)    {
        scanf("%d", &nums[i]);
        if(pts.find(nums[i]) == pts.end())  pts.insert(nums[i]);
    }

    cout << solve();

    return 0;
}