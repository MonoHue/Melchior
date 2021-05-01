#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int nums[110];

void swapinterval(int s, int e)    {
    for(int i = s;i <= (s + e) / 2;i++) swap(nums[i], nums[s + e - i]);
}

int main()  {
    int testcases;
    cin >> testcases;
    for(int tc = 1;tc <= testcases;tc++)    {
        int n, maxc;
        cin >> n >> maxc;
        for(int i = 1;i <= n;i++)   nums[i] = i;

        if(maxc < n - 1)    {
            printf("Case #%d: IMPOSSIBLE\n", tc);
            continue;
        }
        maxc -= (n - 1);
        int end = n;
        for(int i = 1;i < end && maxc > 0;i++) {
            if(end - i >= maxc)  {
                swapinterval(i, i + maxc);
                maxc = 0;
                break;
            }
            swapinterval(i, end);
            maxc -= (end - i);
            if(end - i - 1 >= maxc) {
                swapinterval(i, i + maxc);
                maxc = 0;
                break;
            }
            swapinterval(i, end - 1);
            maxc -= (end - i - 1);
            end--;
        }

        if(maxc > 0)    printf("Case #%d: IMPOSSIBLE\n", tc);
        else {
            printf("Case #%d:", tc);
            for(int i = 1;i <= n;i++)   printf(" %d", nums[i]);
            printf("\n");
        }

    }


    return 0;
}