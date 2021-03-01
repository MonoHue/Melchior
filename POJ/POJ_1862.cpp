#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

const int RANGE = 110;

int n = 0;
double ans = 0;
double nums[RANGE];

double cal(double m1, double m2)  {
    return 2.0 * sqrt(m1 * m2);
}

int main()  {
    cin >> n;

    for(int i = 0;i < n;i++)    cin >> nums[i];
    sort(nums, nums + n, greater<double>());

    if(n == 1)  {
        cout << fixed << setprecision(3) << nums[0];
    }
    else    {
        ans = cal(nums[0], nums[1]);

        for(int i = 2;i < n;i++)    ans = cal(ans, nums[i]);

        cout << fixed << setprecision(3) <<  ans;
    }

    return 0;
}