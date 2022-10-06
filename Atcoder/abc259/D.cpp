// EPS ERROR, not fixed

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Circle{
    long long x;
    long long y;
    long long r;
}circle[3002];
bool d[3002];
vector<int> e[3002];

long long distSquared(long long x, long long y, long long a, long long b) {
    return (x - a) * (x - a) + (y - b) * (y - b);
}

int main() {
    int n;
    cin >> n;
    long long sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    for(int i = 1;i <= n;i++)
        cin >> circle[i].x >> circle[i].y >> circle[i].r;

    for(int i = 1;i <= n;i++)   {
        if(circle[i].r * circle[i].r == distSquared(sx, sy, circle[i].x, circle[i].y))  {
            e[0].emplace_back(i);
            e[i].emplace_back(0);
        }
        if(circle[i].r * circle[i].r == distSquared(tx, ty, circle[i].x, circle[i].y))  {
            e[n + 1].emplace_back(i);
            e[i].emplace_back(n + 1);
        }
    }

    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)   {
            double dist = distSquared(circle[i].x, circle[i].y, circle[j].x, circle[j].y);
            dist = sqrt(dist);
            long long &r1 = circle[i].r, &r2 = circle[j].r;
            if(r1 + r2 >= dist && r1 + dist > r2 && r2 + dist > r1) {
                e[i].emplace_back(j);
                e[j].emplace_back(i);
            }
        }

    queue<int> points;
    points.push(0);
    while(!points.empty())  {
        int p = points.front();
        points.pop();
        if(d[p]) continue;
        else d[p] = true;
        for(auto t: e[p])
            points.push(t);
    }

    if(d[n + 1])    cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}