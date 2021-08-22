#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- > 0) {
        int n, m;
        priority_queue<int, vector<int> > a, b;
        scanf("%d%d", &n, &m);
        bool fail = false;

        for (int i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            a.push(t);
        }
        for (int i = 0; i < m; i++) {
            int t;
            scanf("%d", &t);
            b.push(t);
        }

        while (!a.empty()) {
            if (b.empty()) {
                fail = true;
                break;
            }
            int t1 = a.top(), t2 = b.top();
            a.pop();
            b.pop();
            t2 -= t1;
            if (t2 > 0) b.push(t2);
            else if (t2 < 0) {
                fail = true;
                break;
            }
        }

        if (fail) printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}
