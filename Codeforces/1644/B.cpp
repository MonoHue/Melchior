#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;

int nums[51];

int main() {
    int testcases;
    cin >> testcases;
    for (int i = 0; i < 51; i++) nums[i] = 50 - i + 1;
    while (testcases--) {
        cin >> n;
        if(n == 3)  {
            printf("1 3 2\n2 3 1\n3 1 2\n");
        }
        else{
            for(int i = 0;i < n;i++)    {
                for(int j = i;j > 0;j--)    printf("%d ", j);
                for(int j = n;j > i;j--)    printf("%d ", j);
                printf("\n");
            }
        }


    }
    return 0;

}

