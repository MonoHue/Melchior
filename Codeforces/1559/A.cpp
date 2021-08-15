#include <iostream>
using namespace std;

int nums[1000];

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        int n;
        cin >> n;
        for(int i = 0;i < n;i++)    cin >> nums[i];

        int ans = nums[0];
        for(int i = 1;i < n;i++)    ans &= nums[i];

        cout << ans << endl;
    }

    return 0;
}