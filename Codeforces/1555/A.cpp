#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        long long n;
        cin >> n;

        if(n <= 6)  {cout << 15 << endl;continue;}
        if(n <= 8)  {cout << 20 << endl;continue;}
        if(n <= 10)  {cout << 25 << endl;continue;}
        long long ans = 0;
        ans = n - n % 6;
        n %= 6;
        if(n == 0)  ;
        else if (n == 1)    ans += 2;
        else if (n == 2)    ans += 2;
        else if (n == 3)    ans += 4;
        else if (n == 4)    ans += 4;
        else if (n == 5)    ans += 6;

        ans *= 5;
        ans /= 2;

        cout << ans << endl;
    }

    return 0;
}