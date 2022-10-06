#include <iostream>

using namespace std;

int main()  {
    int testcases;cin >> testcases;
    for(int testcase = 1;testcase <= testcases;testcase++)  {
        int n, k, sum = 0;
        cin >> n >> k;
        for(int i = 0;i < n;i++)    {
            int t;
            cin >> t;
            sum += t;
            sum %= k;
        }
        cout << "Case #" << testcase << ": " << sum << endl;
    }

    return 0;
}