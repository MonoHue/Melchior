#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string a, b;

int count(string str)   {
    int cnt = 0;
    for(int i = 0;i < str.size() - 1;i++)
        if(str[i] != str[i + 1])
            cnt ++;

    return cnt;
}

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int num;
        cin >> num;
        if(count(a) != count(b))    {
            cout << -1 << endl;
            continue;
        }
        if(a.front() != b.front() || a.back() != b.back())    {
            cout << -1 << endl;
            continue;
        }

        vector<int> locA;
        vector<int> locB;

        for(int i = 0;i < a.size() - 1;i++)
            if(a[i] != a[i + 1])
                locA.emplace_back(i);

        for(int i = 0;i < b.size() - 1;i++)
            if(b[i] != b[i + 1])
                locB.emplace_back(i);

        long long ans = 0;
        for(int i = 0;i < locA.size();i++)  {
            ans += max(locA[i] - locB[i], locB[i] - locA[i]);
        }

        cout << ans << endl;
    }

    return 0;
}