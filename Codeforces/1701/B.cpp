//TODO: https://codeforces.com/contest/1701/problem/B

#include <cstdio>
#include <iostream>

using namespace std;

bool exist[200010];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++)
            exist[i] = false;

        int cnt = 0;
        printf("2\n");
        while(++cnt <= n) {
            if(exist[cnt])
                continue;
            exist[cnt] = true;

            if(cnt * 2 <= n)    {
                exist[2*cnt] = true;
                printf("%d %d ", cnt, 2 * cnt);
            }
            else printf("%d ", cnt);
        }

        printf("\n");
    }

    return 0;
}