#include <cstdio>
#include <iostream>
using namespace std;

int n;
int nums[200010];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        bool ok = true;
        cin >> n;
        for(int i = 0;i < n;i++)
            scanf("%d", &nums[i]);

        long long preSum = 0;
        for(int i = 0;i < n;i++)
            preSum += nums[i];
        if(preSum == 0) {
            for(int i = 0;i < n && ok;i++)    {
                preSum += nums[i];
                if(preSum == 0) {
                    while(i + 1 < n)    {
                        i++;
                        if(nums[i] != 0)    ok = false;
                    }
                }
                else if (preSum < 0)    ok = false;
            }
        }
        else ok = false;

        if(ok)  cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}