#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long nums[1000100];

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        int n, k;
        long long ans = -10000000000;
        cin >> n >> k;
        for(int i = 1;i <= n;i++)    cin >> nums[i];
        for(int i = n;i > max(0, n - 150);i--) for(int j = n;j > max(0, n - 150);j--) {
            if(i == j)    continue;
            ans = max(ans, i * j - k * (nums[i] | nums[j]));
        }

        cout << ans << endl;
    }
    
    return 0;
}