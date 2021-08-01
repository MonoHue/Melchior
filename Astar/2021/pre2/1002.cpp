#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int nums[1000100];

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        long long n, k;

        cin >> n >> k;
        for(int i = 0;i < n;i++)    scanf("%d", &nums[i]);

        sort(nums, nums + n);

        int last = nums[0] - k - 1;
        int cnt = 0;
        for(int i = 0;i < n;i++)    {
            if(last < nums[i] - k)  {
                cnt++;
                last = nums[i] - k;
            }
            else if(last >= nums[i] + k)    {
                continue;
            }
            else    {
                cnt++;
                last++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}