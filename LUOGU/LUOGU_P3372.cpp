#include <cstdio>
using namespace std;

const int RANGE = 10e5 + 10;

int n = 1, dat[RANGE * 2];

int main() {
    int n_, m;
    scanf("%d%d", &n_, &m);
    while (n < n_) n_ <<= 1;
    for (int i = 0; i < n_; i++) {
        int t;
        scanf("%d", &t);
        update(i, t);
    }
    while (m-- > 0) {
        int opt, x, y, k;
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1) { //Add
            scanf("%d", &k);
            update(x, k);
        } else {   //Sum

        }
    }

    return 0;
}