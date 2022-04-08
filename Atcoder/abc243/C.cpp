#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int RANGE = 2e5 + 10;

int n;
struct People {
    int x;
    int y;
    char f;
} people[RANGE];
char tmp[RANGE];

bool cmp(People a, People b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.f != b.f) return a.f < b.f;
    return a.x < b.x;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &people[i].x, &people[i].y);
    }
    scanf("%s", tmp);
    for (int i = 0; i < n; i++) people[i].f = tmp[i];

    sort(people, people + n, cmp);

    int tx = 0, ty = -1;
    bool fail = false;
    for (int i = 0; i < n; i++) {
        if (ty != people[i].y) {
            ty = people[i].y;
            tx = people[i].x;
            continue;
        }

        if (tx > people[i].x) fail = true;
        tx = people[i].x;
    }

    if (fail) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}