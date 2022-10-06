#include <cstdio>
#include <iostream>
using namespace std;

int nums[200];

int main() {
    int testcases;cin >> testcases;
    while (testcases --> 0) {
        int n;
        scanf("%d", &n);
        for(int i = 0;i < n;i++)
            scanf("%d", &nums[i]);

        printf("%d\n", nums[0]);

    }

    return 0;
}