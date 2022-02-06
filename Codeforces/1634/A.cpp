#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0) {
        int n, k;
        cin >> n >> k;
        string str, revStr;
        cin >> str;
        revStr = str;
        reverse(revStr.begin(), revStr.end());
        if (str == revStr || k == 0) cout << 1 << endl;
        else cout << 2 << endl;
    }

    return 0;
}