#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 10;

int n, m;
int head[MAX_N], d[MAX_N];

int find(int x) {
    if(head[x] == x)    return x;
    return head[x] = find(head[x]);
}

void merge(int a, int b)    {
    head[find(a)] = find(b);
}

class Capability{
public:
    int count = 0;
    queue<pair<int, int> > points;
};

int main()  {
    scanf("%d%d", &n, &m);

    for(int i = 1;i <= n;i++)    scanf("%d", &d[i]);
    for(int i = 1;i <= n;i++)    head[i] = i;
    for(int i = 0;i < m;i++) {
        int opt1, opt2;
        scanf("%d%d", &opt1, &opt2);
        d[opt1]--;
        d[opt2]--;

        merge(opt1, opt2);
    }

    map<int, Capability> cap;
    for(int i = 1;i <= n;i++)   {
        if(d[i] == 0)   continue;

        int ancestor = find(i);
        cap[ancestor].count += d[i];
        cap[ancestor].points.push(make_pair(i, d[i]));
    }

    priority_queue<pair<int, int> > p;
    for(auto node:cap)  {
        p.push(make_pair(node.second.count, node.first));
    }

    while(p.size() != 1)    {
        auto opt1 = p.top();
        p.pop();
        auto opt2 = p.top();
        p.pop();

        opt1.first--;
        p.push(opt1);
        opt2.first--;
        p.push(opt2);
    }









    return 0;
}