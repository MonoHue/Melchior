#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int testcases;cin >> testcases;
    while (testcases --> 0) {
        int n;
        scanf("%d", &n);

        int last = 0;
        int cnt = 0;
        for (int i = 0;i < n;i++)   {
            int t;
            scanf("%d", &t);
            if(last != 0 && t == 0)
                cnt++;

            last = t;
        }
        if(last != 0)   cnt++;
        if(cnt > 2) cnt = 2;

        cout << cnt << endl;
    }

    return 0;
}