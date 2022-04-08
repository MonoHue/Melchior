#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> pattern;

int directs[][2] = {{0,  1},
                    {1,  0},
                    {1,  1},
                    {-1, 1}};

bool search(int x, int y) {
    int cnt = 6;
    for (auto direct: directs) {
        int tmp = 0;
        for (int dx = 0, dy = 0; dx < 6 && dy < 6;
             dx += direct[0], dy += direct[1]) {
            if (!(x + dx < n && y + dy < n && x + dx >= 0 && y + dy >= 0)) {
                tmp = 100000;
                break;
            }
            if (pattern[x + dx][y + dy] != '#') tmp++;;
        }
        cnt = min(tmp, cnt);
    }
    if (cnt < 3) return true;
    else return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        pattern.emplace_back(str);
    }

    bool ok = false;
    for (int i = 0; i < n && !ok; i++)
        for (int j = 0; j < n && !ok; j++) {
            ok = search(i, j);
        }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}