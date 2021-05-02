#include <iostream>
#include <cmath>
using namespace std;

int main()  {
    int testcases;
    cin >> testcases;

    while(testcases --> 0)  {
        int t;
        cin >> t;
        if(t % 2 != 0)  printf("NO\n");
        else {
            int t1, t2;
            t1 = sqrt(t / 2);
            t2 = sqrt(t / 4);
            if (t1 * t1 == t / 2 || (t2 * t2 == t / 4 && t % 4 == 0)) {
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }

    return 0;
}