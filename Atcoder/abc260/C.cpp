#include <iostream>

using namespace std;

long long x, y;
long long a[11], b[11];

void checkLevel(int level) {
    a[level - 1] += (1 + x) * a[level] + b[level];
    b[level - 1] += x * y * a[level] + y * b[level];
}

int main() {
    int t;
    cin >> t;
    a[t] = 1;
    cin >> x >> y;

    for (int i = t; i >= 2; i--)
        checkLevel(i);

    cout << b[1] << endl;

    return 0;
}