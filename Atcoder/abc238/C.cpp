#include <iostream>

using namespace std;

const int MOD = 998244353;

long long sum(long long first, long long end) {
    long long a = (first + end) % MOD;
    long long b = (end - first + 1) % MOD;
    return a * b / 2 % MOD;
}

long long n;

int main() {
    long long ans = 0;
    cin >> n;

    long long locate = 10;
    for (; locate <= n; locate *= 10) {
        ans += sum(1, locate / 10 * 9);
        ans %= MOD;
    }

    locate /= 10;
    ans += sum(1, n - locate + 1);
    ans %= MOD;

    cout << ans;


    return 0;
}