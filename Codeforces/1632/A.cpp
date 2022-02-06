#include <iostream>

using namespace std;

int main()  {
    int testcase;cin >> testcase;
    while (testcase-->0)    {
        int n;
        string str;
        cin >> n >> str;

        int cnt1 = 0, cnt2 = 0;
        for(auto c:str) {
            if(c == '0')    cnt1++;
            else cnt2++;
        }

        if(cnt1 >= 2 || cnt2 >= 2)  cout << "NO" << endl;
        else cout << "YES" << endl;

    }

    return 0;
}