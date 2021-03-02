#include <iostream>
#include <cstdio>
#define TRANGE 1010
#define WRANGE 35
using namespace std;

int t, w;
int dp[TRANGE][WRANGE];
bool isleft[TRANGE];    //Consider 1 as left, 2 as right

int main()  {
    cin >> t >> w;

    for(int i = 1;i <= t;i++)   {
        int t;
        scanf("%d", &t);
        if(t == 1)  isleft[i] = true;
        else isleft[i] = false;
    }

    //TODO: the Situation Expression?
    for(int i = 1;i <= t;i++)   {
        for(int j = 1;j <= w;j++)   {

        }

    }

    return 0;
}