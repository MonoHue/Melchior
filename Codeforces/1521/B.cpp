#include <iostream>
#include <cstdio>
using namespace std;

int nums[100010];

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        int len;

        int minval = 2000000010, mini;
        scanf("%d", &len);
        for(int i = 0;i < len;i++) {
            scanf("%d", &nums[i]);
            if(nums[i] < minval)    {
                minval = nums[i];
                mini = i;
            }
        }

        if(mini == 0) {
            printf("%d\n", len - 1);
            for(int i = 1;i < len;i++)  {
                printf("1 %d %d %d\n", i + 1, minval, minval + i);
            }
        }
        else    {
            printf("%d\n", len);
            printf("1 %d %d %d\n", mini + 1, minval, nums[0]);
            for(int i = 1;i < len;i++)  {
                printf("1 %d %d %d\n", i + 1, minval, minval + i);
            }
        }

    }

    return 0;
}