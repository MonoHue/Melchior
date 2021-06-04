#include <iostream>
#include <cstdio>
using namespace std;

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        long long a,b,x,y;
        cin >> a >> b;
        if(b == 1)  printf("NO\n");
        else    {
            if(b == 2)  {
                x = 1;
                y = 2;
            }
            else    {
                x = 1;
                y = b - x;
            }
            printf("YES\n%lld %lld %lld\n", a * x, a * y, a * (x+y));
        }

    }

    return 0;
}