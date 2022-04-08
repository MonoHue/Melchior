#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <tuple>

using namespace std;

const int WILDCOLOUR = 1e8 + 19260817;

int n, m, cnt = 0;
int colour[1010][1010];
bool visited[1010][1010];
queue<pair<int, int> > bfs;
vector<tuple<int, int, int> > opts;

int getColor(int x, int y) {
    int color = colour[x][y];
    if (color == WILDCOLOUR) color = colour[x + 1][y];
    if (color == WILDCOLOUR) color = colour[x][y + 1];
    if (color == WILDCOLOUR) color = colour[x + 1][y + 1];

    return color;
}

bool isValid(int x, int y) {
    return (x >= 0) && (x + 1 < n) && (y >= 0) && (y + 1 < m);
}

bool isSame(int x, int y) {
    if (!isValid(x, y) || visited[x][y]) return false;
    int &a = colour[x][y];
    int &b = colour[x + 1][y];
    int &c = colour[x][y + 1];
    int &d = colour[x + 1][y + 1];

    if (a == WILDCOLOUR) return false;
    return a == b && b == c && c == d;
}

bool isOneColour(int x, int y) {
    if (!isValid(x, y) || visited[x][y]) return false;
    int &a = colour[x][y];
    int &b = colour[x + 1][y];
    int &c = colour[x][y + 1];
    int &d = colour[x + 1][y + 1];
    int sum = a + b + c + d;

    if (sum == 4 * WILDCOLOUR) return false;
    int color = getColor(x, y);

    return (a == color || a == WILDCOLOUR) && (b == color || b == WILDCOLOUR) && (c == color || c == WILDCOLOUR) &&
           (d == color || d == WILDCOLOUR);
}

void addAnswer(int x, int y) {
    int color = getColor(x, y);

    opts.emplace_back(x + 1, y + 1, color);

    colour[x][y] = WILDCOLOUR;
    colour[x + 1][y] = WILDCOLOUR;
    colour[x][y + 1] = WILDCOLOUR;
    colour[x + 1][y + 1] = WILDCOLOUR;

//    cout << x + 1 << " " << y + 1 << " " << color << endl;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) cout << colour[i][j] << "\t";
//        cout << endl;
//    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &colour[i][j]);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) visited[i][j] = false;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
            if (isSame(i, j)) {
                visited[i][j] = true;
                bfs.push(make_pair(i, j));
            }


    while (!bfs.empty()) {
        pair<int, int> tmp = bfs.front();
        bfs.pop();

        int &x = tmp.first, &y = tmp.second;
        if (colour[x][y] + colour[x + 1][y] + colour[x][y + 1] + colour[x + 1][y + 1] == 4 * WILDCOLOUR) continue;
        addAnswer(x, y);
        int dx = x, dy = y;
        dx = x + 1;
        dy = y + 1;
        if (isOneColour(dx, dy)) {
            visited[dx][dy] = true;
            bfs.push(make_pair(dx, dy));
        }
        dx = x + 1;
        dy = y - 1;
        if (isOneColour(dx, dy)) {
            visited[dx][dy] = true;
            bfs.push(make_pair(dx, dy));
        }
        dx = x - 1;
        dy = y + 1;
        if (isOneColour(dx, dy)) {
            visited[dx][dy] = true;
            bfs.push(make_pair(dx, dy));
        }
        dx = x - 1;
        dy = y - 1;
        if (isOneColour(dx, dy)) {
            visited[dx][dy] = true;
            bfs.push(make_pair(dx, dy));
        }
        dx = x + 1;
        dy = y;
        if (isOneColour(dx, dy)) {
            visited[dx][dy] = true;
            bfs.push(make_pair(dx, dy));
        }
        dx = x - 1;
        dy = y;
        if (isOneColour(dx, dy)) {
            visited[dx][dy] = true;
            bfs.push(make_pair(dx, dy));
        }
        dx = x;
        dy = y + 1;
        if (isOneColour(dx, dy)) {
            visited[dx][dy] = true;
            bfs.push(make_pair(dx, dy));
        }
        dx = x;
        dy = y - 1;
        if (isOneColour(dx, dy)) {
            visited[dx][dy] = true;
            bfs.push(make_pair(dx, dy));
        }
    }

    bool fail = false;
    for (int i = 0; i < n && !fail; i++)
        for (int j = 0; j < m && !fail; j++)
            if (colour[i][j] != WILDCOLOUR) {
                fail = true;
            }

    if (fail) cout << -1 << endl;
    else {
        printf("%lu\n", opts.size());
        reverse(opts.begin(), opts.end());
        for (auto opt: opts) {
            printf("%d %d %d\n", get<0>(opt), get<1>(opt), get<2>(opt));
        }
    }

    return 0;
}