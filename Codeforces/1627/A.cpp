#include <iostream>

using namespace std;

int n, m, r, c;

char mapp[75][75];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        cin >> n >> m >> r >> c;

        r--;
        c--;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> mapp[i][j];

        if (mapp[r][c] == 'B') {
            cout << 0 << endl;
            continue;
        }

        bool isOne = false;
        for (int i = 0; i < n && !isOne; i++) if (mapp[i][c] == 'B') isOne = true;
        for (int j = 0; j < m && !isOne; j++) if (mapp[r][j] == 'B') isOne = true;
        if (isOne) {
            cout << 1 << endl;
            continue;
        }

        bool isTwo = false;

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (mapp[i][j] == 'B') isTwo = true;

        if (isTwo) cout << 2 << endl;
        else cout << -1 << endl;
    }

    return 0;
}