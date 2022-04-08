#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const long long FAIL1 = -1;
const long long FAIL2 = 10ll + 1e18;

int n;
multiset<long long> s;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 6; i++) {
        s.insert(FAIL1);
        s.insert(FAIL2);
    }
    for (int q = 0; q < n; q++) {
        int opt, k;
        long long num;
        scanf("%d%lld", &opt, &num);
        if (opt != 1) scanf("%d", &k);

        if (opt == 1) s.insert(num);
        else if (opt == 2) {
            auto it = s.upper_bound(num);
            it--;
            while (k-- > 1) it--;
            if (*it == FAIL1 || *it == FAIL2) printf("-1\n");
            else printf("%lld\n", *it);
        } else if (opt == 3) {
            auto it = s.lower_bound(num);
            while (k-- > 1) it++;
            if (*it == FAIL1 || *it == FAIL2) printf("-1\n");
            else printf("%lld\n", *it);
        }

    }

    return 0;
}