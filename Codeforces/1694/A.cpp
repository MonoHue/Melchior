#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int a, b;
        cin >> a >> b;
        string ans;

        if (a < b) {
            b -= a;
            while (a-- > 0) ans += "10";
            ans += string(b, '1');
        } else {
            a -= b;
            while (b-- > 0) ans += "01";
            ans += string(a, '0');
        }

        cout << ans << endl;
    }

    return 0;
}