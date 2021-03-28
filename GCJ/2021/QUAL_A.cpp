#include <iostream>
#include <algorithm>
using namespace std;

int nums[100];

int main()  {
    int testcases;
    cin >> testcases;
    for(int testcase = 1;testcase <= testcases;testcase++)  {
        int n, ans = 0;
        cin >> n;

        for(int i = 0;i < n;i++)    cin >> nums[i];

        for(int i = 0;i < n - 1;i++)    {
            int minplace = 0, minn = 2000000;
            for(int j = i;j < n;j++)    {
                if(minn > nums[j])  {
                    minn = nums[j];
                    minplace = j;
                }
            }
            ans += (minplace - i + 1);
            for(int k = i;k <= (minplace + i) / 2;k++)   swap(nums[k], nums[minplace + i - k]);
        }

        cout << "Case #" << testcase << ": " << ans << endl;

    }

    return 0;
}