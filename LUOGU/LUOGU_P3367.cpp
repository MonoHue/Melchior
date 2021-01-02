#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#define range 10005

int	disjoint[range];
int rank[range];

int findfoog(int x) {
    if (disjoint[x] == x)	return x;
    else
    {
        disjoint[x] = find(disjoint[x]);
        rank[disjoint[x]]++;
    }
    return disjoint[x];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)	return;

    if (rank[a] > rank[b]) {
        disjoint[b] = a;
        rank[a] += rank[b];
    }
    else
    {
        disjoint[a] = b;
        rank[b] += rank[a];
    }
}
int main() {
    int n, m, t, op1, op2;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)	disjoint[i] = i;
    while (m--) {
        scanf("%d%d%d", &t, &op1, &op2);
        if (t == 1)	merge(op1, op2);
        else if (find(op1) == find(op2))	printf("Y\n");
        else printf("N\n");
    }

    return 0;

}