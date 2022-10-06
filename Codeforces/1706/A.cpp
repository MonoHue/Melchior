#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        int n, m;
        cin >> n >> m;

        string str(m, 'B');

        while(n --) {
            int t;
            cin >> t;
            t -= 1;
            int small = min(t, m - t - 1);
            int big = max(t, m - t - 1);
            if(str[small] == 'B')
                str[small] = 'A';
            else
                str[big] = 'A';
        }

        cout << str << endl;

    }

    return 0;
}