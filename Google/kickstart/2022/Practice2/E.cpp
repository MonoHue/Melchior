#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int direct[4][2] = {{1,  0},
                    {-1, 0},
                    {0,  1},
                    {0,  -1}};
int distMap[300][300];

bool coordCheck(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int test(int x, int y) {
    if(!coordCheck(x, y))
        return int(1e9);

    int testMap[n][m];
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            testMap[i][j] = distMap[i][j];

    queue<pair<int, int> > upd;
    testMap[x][y] = 0;
    upd.emplace(x, y);

    while(!upd.empty()) {
        pair<int, int> t = upd.front();
        upd.pop();
        for (int i = 0; i < 4; i++) {
            int &dx = direct[i][0], &dy = direct[i][1];
            if (coordCheck(t.first + dx, t.second + dy) &&
                testMap[t.first + dx][t.second + dy] > testMap[t.first][t.second] + 1) {
                testMap[t.first + dx][t.second + dy] = testMap[t.first][t.second] + 1;
                upd.emplace(t.first + dx, t.second + dy);
            }
        }
    }

    int maxi = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (maxi < testMap[i][j]) maxi = testMap[i][j];

    return maxi;
}

int main() {
    int testcases;
    cin >> testcases;
    for (int testcase = 1; testcase <= testcases; testcase++) {
        cin >> n >> m;
        queue<pair<int, int> > flood;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                distMap[i][j] = 1e9;

        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < m; j++)
                if (tmp[j] == '1') {
                    flood.emplace(i, j);
                    distMap[i][j] = 0;
                }
        }

        while (!flood.empty()) {
            pair<int, int> t = flood.front();
            int &x = t.first, &y = t.second;
            flood.pop();
            for (int i = 0; i < 4; i++) {
                int &dx = direct[i][0], &dy = direct[i][1];
                if (coordCheck(x + dx, y + dy) &&
                    distMap[x + dx][y + dy] > distMap[x][y] + 1) {
                    distMap[x + dx][y + dy] = distMap[x][y] + 1;
                    flood.emplace(x + dx, y + dy);
                }
            }
        }

        int maxi = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (distMap[i][j] > maxi) maxi = distMap[i][j];

        int accumX = 0, accumY = 0, cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (distMap[i][j] == maxi) {
                    accumX += i;
                    accumY += j;
                    cnt++;
                }
            }

        accumX /= cnt;
        accumY /= cnt;
        int ans = 1e9;
        for(int i = -2;i <= 2;i++)
            for(int j = -2;j <= 2;j++)
                ans = min(ans, test(accumX+i, accumY+j));

        cout << "Case #" << testcase << ": " << ans << endl;
    }

    return 0;
}