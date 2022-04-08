#include <iostream>

using namespace std;

int n;
long long x;
string str;

void peek(int index) {
    if (index == 0) {
        x /= 2;
        str.erase(0, 1);
        return;
    } else if (str[index - 1] == 'U') peek(index - 1);
    else str.erase(index - 1, 2);
}

int main() {
    cin >> n >> x;
    cin >> str;

    int uCnt = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == 'U') {
            uCnt++;
            str.erase(i, 1);
            continue;
        }
        else if (uCnt == 0) continue;

        uCnt--;
        str.erase(i, 1);
    }
    while (uCnt-- > 0) x /= 2;
    for (auto c: str) {
        if (c == 'R') x = 2 * x + 1;
        else if (c == 'L') x = 2 * x;
        else x /= 2;
    }

    cout << x << endl;

    return 0;
}