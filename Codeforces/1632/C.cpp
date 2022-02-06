#include <iostream>

using namespace std;

const int MAX_LEN = 24;
int pow2[MAX_LEN];

void make_pow() {
    pow2[0] = 1;
    for (int i = 1; i < MAX_LEN; i++) pow2[i] = 2 * pow2[i - 1];
}

int solve(int a, int b) {
    for (int i = MAX_LEN - 1; i >= 0; i--) {
        if (a >= pow2[i]) break;
        if (pow2[i] <= b) b -= pow2[i];
    }

    for (int i = MAX_LEN - 1; i >= 0; i--) {
        if (pow2[i] > a && pow2[i] > b) continue;
        if (a >= pow2[i] && b < pow2[i]) break;

        if (a >= pow2[i]) a -= pow2[i];
        if (b >= pow2[i]) b -= pow2[i];
    }

    return max(0, a - b) + 1;
}

int main() {
    make_pow();
    int testcase;
    cin >> testcase;
    while (testcase-- > 0) {
        int a, b;
        cin >> a >> b;

        int ans = 1000000;
        for (int i = a; i < b; i++) {
            ans = min(ans, i - a + solve(i, b));
        }
        cout << min(b - a, ans) << endl;

    }

    return 0;
}