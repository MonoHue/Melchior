#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

long long nums[200010];

int main() {
    int testcases;cin >> testcases;
    while (testcases --> 0) {
        int n;
        bool hasZero = false;
        scanf("%d", &n);
        for(int i = 0;i < n;i++) {
            long long t;
            scanf("%lld", &t);
            if(t == 0)  {
                i--;
                n--;
                hasZero = true;
            }
            else nums[i] = t;
        }

        if(n < 2)  cout << "YES" << endl;
        else if(n == 2 && nums[0] + nums[1] == 0)   cout << "YES" << endl;
        else if(n > 4)  cout << "NO" << endl;
        else {
            bool ok = true;
            set<long long> s;
            for(int i = 0;i < n;i++)    s.insert(nums[i]);
            if(hasZero) s.insert(0ll);

            for(int i = 0;i < n;i++)
                for(int j = i + 1;j < n;j++)
                    for(int k = j + 1;k < n;k++)    {
                        long long sum = nums[i] + nums[j] + nums[k];
                        if(s.find(sum) == s.end())
                            ok = false;
                    }

            if(hasZero)
                for(int i = 0;i < n;i++)
                    for(int j = i + 1;j < n;j++)    {
                        long long sum = nums[i] + nums[j];
                        if(s.find(sum) == s.end())
                            ok = false;
                    }

            if(ok)  cout << "YES" << endl;
            else cout << "NO" << endl;
        }

    }

    return 0;
}