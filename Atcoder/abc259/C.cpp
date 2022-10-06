#include <iostream>
#include <cstdio>

using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    decltype(a.size()) aLoc = 0, bLoc = 0;
    while (aLoc < a.size() && bLoc < b.size()) {
        int aCnt = 0, bCnt = 0;
        char aC = a[aLoc], bC = b[bLoc];

        while (aLoc < a.size() && aC == a[aLoc]) {
            aLoc++;
            aCnt++;
        }

        while (bLoc < b.size() && bC == b[bLoc]) {
            bLoc++;
            bCnt++;
        }

        if (aC != bC) {
            cout << "No" << endl;
            return 0;
        }

        if ((aLoc == a.size() && bLoc != b.size()) ||
            (aLoc != a.size() && bLoc == b.size())) {
            cout << "No" << endl;
            return 0;
        }

        if ((aCnt == 1 && bCnt != 1) ||
            (aCnt != 1 && bCnt == 1) ||
            aCnt > bCnt) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}