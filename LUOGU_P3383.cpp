#include <cstdio>
#define RANGE 100010000
using namespace std;

int prime[RANGE];
bool arr[RANGE];

int main()  {
    int n ,k ,t ,cnt = 0;
    scanf("%d%d", &n, &k);

    for (int i = 2;i <= n;i++) {
        if (arr[i] == false)    prime[cnt++] = i;
        for (int j = 0;j < cnt && (long long) i * prime[j] <= n;j ++) {
            arr[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }

    for (int i = 0;i < k;i++)   {
        scanf("%d", &t);
        printf("%d\n", prime[t - 1]);
    }

    return 0;
}
