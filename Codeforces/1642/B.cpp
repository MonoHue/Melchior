#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

int n;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        scanf("%d", &n);
        map<int, int> m;
        for(int i = 0;i < n;i++)    {
            int t;
            scanf("%d", &t);
            m[t]++;
        }

        int ans = 0;
        for(auto key:m) {
            ans += key.second - 1;
        }

        for(int i = 0;i < n - ans;i++)    printf("%d ", n - ans);
        for(int i = n - ans;i < n;i++)  printf("%d ", i + 1);

        printf("\n");
    }
    return 0;

}

