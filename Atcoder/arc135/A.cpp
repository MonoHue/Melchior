#include <iostream>
#include <algorithm>

using namespace std;

const long long MOD = 998244353;
const long long RANGE = 100000000;

int value[RANGE];

long long solve(long long n)    {
    if(n < RANGE)   return value[n];

    long long l = n / 2;
    long long r = (n + 1) / 2;
    if(l == r)  {
        long long val = solve(l);
        return val * val % MOD;
    }
    else {
        return solve(l) * solve(r) % MOD;
    }
}

int main() {
    value[0] = 0;
    value[1] = 1;
    value[2] = 2;
    value[3] = 3;
    value[4] = 4;

    long long num;
    cin >> num;
    for(int i = 5;i < RANGE;i++)   {
        int l = i / 2;
        int r = (i + 1) / 2;
        long long val = value[l];
        val *= value[r];
        value[i] = val % MOD;
    }


    cout << solve(num);


    return 0;
}