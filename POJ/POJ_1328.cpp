#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int numofislands;
double radius;
pair<double, double> islands[10000];

bool cmp(pair<double, double> a, pair<double, double> b)    {
    if(a.second < b.second) return true;
    if(a.second == b.second && a.first < b.first)   return true;
    return false;
}

int main()  {
    int casenumber = 1;
    scanf("%d%lf", &numofislands, &radius);
    while(numofislands != 0) {
        bool valid = true;
        for(int i = 0;i < numofislands;i++)    {
            double t1, t2;
            scanf("%lf%lf", &t1, &t2);

            //(x, y) -> range on x-axis
            double delta = radius * radius - t2 * t2;
            if(delta < 0 || radius < 0) valid = false;  //Radius may be negative in POJ.
            else delta = sqrt(delta);
            islands[i].first = t1 - delta;
            islands[i].second = t1 + delta;
        }

        if(valid) {
            sort(islands, islands + numofislands, cmp);

            int cnt = 1;
            double pos = islands[0].second;
            for (int i = 0; i < numofislands; i++) {
                if (islands[i].first <= pos && pos <= islands[i].second) continue;
                pos = islands[i].second;
                cnt++;
            }

            printf("Case %d: %d\n", casenumber, cnt);
        }
        else    printf("Case %d: -1\n", casenumber);

        scanf("%d%lf", &numofislands, &radius);
        casenumber++;
    }

    return 0;

}
/*
2 3
0 2
2 3

2 3
0 2
1 3

3 3
1 2
-3 2
2 4

8 5
2 4
-4 4
-3 3
-3 1
-3 0
-1 0
0 5
6 0

3 0
1 2
-3 1
2 1

3 2
1 2
-3 1
2 1

1 2
0 2


2 3
0 2
2 3

4 -5
4 3
4 3
2 3
6 -9

3 -3
1 2
-3 2
2 1

6 2
1 2
1 2
1 2
-3 1
2 1
0 0

1 2
0 2

2 3
0 2
1 3

3 10
1 10
2 3
4 5

3 5
1 10
2 3
4 5

4 7
1 10
2 3
4 5
0 0

3 9
1 10
2 3
4 5
0 0
*/