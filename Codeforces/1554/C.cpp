#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        int n, m;
        cin >> n >> m;

        if(n > m)   {cout << 0 << endl;continue;}
        vector<int> a;
        vector<int> b;
        while(n != 0)   {
            a.push_back(n & 1);
            n /= 2;
        }
        while(m != 0)   {
            b.push_back(m & 1);
            m /= 2;
        }
        for(int i = a.size();i < b.size();i++)  a.push_back(0);
        for(int i = a.size();i >= 0;i--) {
            if(b[i] == 1 && a[i] == 0)  {
                if(i + 1 == b.size())   {
                    for(int j = i - 1;j >= 0;j--)   b[j] = 0;
                }
                else    {
                    b[i + 1] = 1;
                    for(int j = i;j >= 0;j--)   b[j] = 0;
                }
                break;
            }
        }

        int plus = 1;
        int ans = 0;
        for(int i = 0;i < b.size();i++)    {
            if(b[i] == 1)   ans += plus;
            plus *= 2;
        }

        cout << ans << endl;

    }
    
    return 0;
}