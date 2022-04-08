#include <iostream>
#include <string>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        bool r = false, g = false, b = false;
        string str;
        cin >> str;

        bool ok = true;
        for (auto c: str) {
            if (c == 'r') {
                r = true;
            }
            if (c == 'g') {
                g = true;
            }
            if (c == 'b') {
                b = true;
            }
            if (c == 'R' && !r) ok = false;
            if (c == 'G' && !g) ok = false;
            if (c == 'B' && !b) ok = false;
        }

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}