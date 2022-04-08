#include <iostream>
#include <cstdio>

using namespace std;

int main()  {
    int nums[11];
    for(int i = 0;i < 10;i++)   cin >> nums[i];
    int ans = 0;
    for(int i = 0;i < 3;i++)    ans = nums[ans];

    cout << ans << endl;

    return 0;
}