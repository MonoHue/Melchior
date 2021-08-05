#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int n, ans;
bool isAlive[200010];
set<int> fathers[200010];

void addEdge(int a, int b)  {
    if(a > b)   swap(a, b);
    if(isAlive[a] == true) {
        ans--;
        isAlive[a] = false;
    }
    fathers[a].insert(b);
}

void delEdge(int a, int b)  {
    if(a > b)   swap(a, b);
    fathers[a].erase(b);
    if(fathers[a].empty() && isAlive[a] == false)  {
        ans++;
        isAlive[a] = true;
    }
}

int main()  {
    int m, q;
    scanf("%d%d", &n, &m);
    ans = n;
    for(int i = 0;i < n;i++)    isAlive[i] = true;
    for(int i = 0;i < m;i++)    {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        addEdge(t1, t2);
    }
    cin >> q;
    while(q --> 0)    {
        int opt, t1, t2;
        scanf("%d", &opt);
        if(opt != 3)    scanf("%d%d", &t1, &t2);
        if(opt == 1)    addEdge(t1, t2);
        if(opt == 2)    delEdge(t1, t2);
        if(opt == 3)    cout << ans << endl;
    }

    return 0;
}