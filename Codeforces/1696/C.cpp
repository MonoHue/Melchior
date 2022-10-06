#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int n, m, magic;
        vector<pair<int, long long> > A, B;
        pair<int, long long> last(0, 0);
        scanf("%d%d", &n, &magic);
        for (int i = 0; i < n; i++) {
            int t;
            long long cnt = 1;
            scanf("%d", &t);
            while (t % magic == 0) {
                t /= magic;
                cnt *= magic;
            }

            if (last.first == t) {
                last.second += cnt;
            } else if (last.first != 0) {
                A.emplace_back(last);
                last.first = t;
                last.second = cnt;
            } else {
                last.first = t;
                last.second = cnt;
            }
        }
        if (last.first != 0) {
            A.emplace_back(last);
        }

        last.first = 0;
        last.second = 0;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            int t;
            long long cnt = 1;
            scanf("%d", &t);
            while (t % magic == 0) {
                t /= magic;
                cnt *= magic;
            }

            if (last.first == t) {
                last.second += cnt;
            } else if (last.first != 0) {
                B.emplace_back(last);
                last.first = t;
                last.second = cnt;
            } else {
                last.first = t;
                last.second = cnt;
            }
        }
        if (last.first != 0) {
            B.emplace_back(last);
        }

        if (A.size() != B.size())
            printf("No\n");
        else {
            bool ok = true;
            for (int i = 0; i < A.size(); i++) {
                if (A[i].first != B[i].first || A[i].second != B[i].second) {
                    ok = false;
                    break;
                }
            }

            if (ok) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}