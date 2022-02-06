#include <iostream>
#include <vector>

using namespace std;

string str;

int main()  {
    int testcase;cin >> testcase;
    while (testcase-->0)    {
        cin >> str;
        int cnt0 = 0, cnt1 = 0;
        for(auto c : str)   {
            if(c == '1')    cnt1++;
            else cnt0++;
        }

        if(cnt1 > cnt0) cout << cnt0 << endl;
        else if(cnt1 < cnt0) cout << cnt1 << endl;
        else cout << cnt1 - 1 << endl;

    }

    return 0;
}