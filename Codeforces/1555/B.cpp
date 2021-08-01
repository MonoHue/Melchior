#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxint = 1000000000;

int func(int x, int y)  {
    if(x <= 0)  return 0;
    if(x <= y)  return x;
    return maxint;
}

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        int xside, yside, x1, x2, y1, y2, needx, needy;
        cin >> xside >> yside;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> needx >> needy;

        int ans = maxint;
        ans = min(ans, func(needy - y1, yside - y2));
        ans = min(ans, func(y2 - (yside - needy), y1));
        ans = min(ans, func(needx - x1, xside - x2));
        ans = min(ans, func(x2 - (xside - needx), x1));
        if(ans == maxint)   cout << -1 << endl;
        else cout << ans << endl;


    }
    
    return 0;
}