#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long nums[4];

    for(int i = 0;i < 3;i++)
        cin >> nums[i];

    sort(nums, nums + 3);

    if(nums[2] > nums[0] + nums[1])
        cout << -1 << endl;
    else cout << nums[2] << endl;

    return 0;
}