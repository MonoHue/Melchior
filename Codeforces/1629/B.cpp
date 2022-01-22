#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testcases;cin >> testcases;while (testcases-- > 0) {
        int l, r, k;
        cin >> l >> r >> k;

        if(l == r)  {
            if(l == 1)  cout << "NO" << endl;
            else cout << "YES" << endl;
            continue;
        }

        int odds = r - l;
        if(odds % 2 == 0)  {
            odds /= 2;
            if(l % 2 == 1)  odds++;
        } else {
            odds/=2;
            odds++;
        }
        if(odds <= k)   cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}