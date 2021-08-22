#include <cstdio>

using namespace std;

int nsize, opt, treesize = 1;
const int MAX_N = 1e5 + 10;

int segtree[2 * MAX_N];

void add()  {

}

int query() {
    return 0;
}

int main() {
    scanf("%d%d", &nsize, &opt);
    while (treesize < nsize) treesize <<= 1;

    for (int i = treesize - 1; i < nsize + treesize - 1; i++) scanf("%d", &segtree[i]);
    for (int i = treesize - 2; i >= 0; i--) segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];

    while(opt--)    {
        int order;
        scanf("%d", &order);
        if(order == 1)  {
            int x, y, k;
            scanf("%d%d%d", &x, &y ,&k);
            add(x, y, k);
        }
        else {

        }
    }

    return 0;
}