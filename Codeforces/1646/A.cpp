#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        long long n, s;
        cin >> n >> s;
        cout << s / (n * n) << endl;
    }

    return 0;
}