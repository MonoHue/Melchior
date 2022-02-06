#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cal(int num) {
    int ret = 1;
    while (ret < num) ret *= 2;
    if (ret != num) ret /= 2;
    return ret;
}

int main() {
    int testcase;
    cin >> testcase;
    while (testcase-- > 0) {
        int n;
        cin >> n;
        int mark = cal(n - 1);

        for (int i = mark - 1; i >= 0; i--) cout << i << " ";
        for (int i = mark; i < n; i++) cout << i << " ";

        cout << endl;

    }

    return 0;
}