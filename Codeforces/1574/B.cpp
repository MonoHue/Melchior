#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int nums[4];
int m;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        cin >> nums[0] >> nums[1] >> nums[2] >> m;
        sort(nums, nums + 3);

        if(nums[0] + nums[1] + 1 < nums[2] - m) {
            printf("NO\n");
            continue;
        }

        if(nums[0] + nums[1] + nums[2] - 3 - m < 0) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }

    return 0;
}