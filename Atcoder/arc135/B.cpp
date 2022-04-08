#include <cstdio>
#include <algorithm>

using namespace std;

const int RANGE = 3e5 + 10;

int len;
long long s[RANGE], d[RANGE + 2] = {0, 0};

int main() {
    scanf("%d", &len);
    for (int i = 0; i < len; i++) scanf("%lld", &s[i]);

    for (int i = 2; i < len + 2; i++) {
        d[i] = s[i - 2] - d[i - 1] - d[i - 2];
    }

    long long c1 = 1e9 + 10, c2 = 1e9 + 10, c3 = 1e9 + 10;
    for (int i = 0; i < len + 2; i += 3) c1 = min(c1, d[i]);
    for (int i = 1; i < len + 2; i += 3) c2 = min(c2, d[i]);
    for (int i = 2; i < len + 2; i += 3) c3 = min(c3, d[i]);

    c1 *= -1;
    c2 *= -1;
    if (c1 + c2 > c3) printf("No\n");
    else {
        printf("Yes\n%lld %lld ", c1, c2);

        for (int i = 0; i < len; i++) {
            c3 = s[i] - c1 - c2;
            printf("%lld ", c3);
            c1 = c2;
            c2 = c3;
        }

        printf("\n");
    }

    return 0;
}