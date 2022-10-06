#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long nums[100010], makeItTall[100010];

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        cin >> n;
        for(int i = 0;i < n;i++)
            cin >> nums[i];

        for(int i = 1;i < n- 1;i++)
            makeItTall[i] = max(max(nums[i - 1] + 1 - nums[i], nums[i + 1] + 1 - nums[i]), 0ll);


        long long oddCnt = 0, evenCnt = 0;
        for(int i = 1;i < n - 1;i += 2) {
            oddCnt += max(max(nums[i - 1] + 1 - nums[i], nums[i + 1] + 1 - nums[i]), 0ll);
        }
        for(int i = 2;i < n - 1;i += 2) {
            evenCnt += max(max(nums[i - 1] + 1 - nums[i], nums[i + 1] + 1 - nums[i]), 0ll);
        }

        if(n % 2 == 1)
            cout << oddCnt << endl;
        else    {
            long long minCnt = evenCnt;
            for(int i = 1;i < n - 1;i += 2) {
                evenCnt += makeItTall[i] - makeItTall[i + 1];
                minCnt = min(minCnt, evenCnt);
            }
            cout << minCnt << endl;
        }
    }

    return 0;
}