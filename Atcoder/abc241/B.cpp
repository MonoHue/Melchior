#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<int, int>   noodles;
int plans[1010];

int main()  {
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)    {
        int t;
        cin >> t;
        noodles[t]++;
    }

    bool fail = false;
    for(int i = 0;i < m;i++)    {
        int t;
        cin >> t;
        if(noodles[t] <= 0) {
            fail = true;
            break;
        }
        noodles[t] --;
    }

    if(fail)    cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}