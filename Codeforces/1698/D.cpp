#include <iostream>
#include <cstdio>
#include <random>
#include <set>

using namespace std;

void ask(int l, int r)  {
    cout << "? " << l << " " << r << endl;
}

void submit(int num)    {
    cout << "! " << num << endl;
}

int read(int l, int r)  {
    int cnt = 0;
    int len = r - l + 1;
    for(int i = 0;i < len;i++)   {
        int t;
        cin >> t;
        if(l <= t && t <= r)    cnt++;
    }
    return cnt;
}

int main()  {
    int testcases;cin >> testcases;
    while (testcases --> 0) {
        int l = 1, r;
        cin >> r;
        r++;
        while(r - l > 1)   {
            int mid = (l + r) / 2;
            ask(l, mid - 1);
            if(read(l, mid - 1) % 2 == 1)
                r = mid;
            else l = mid;
        }

        submit(l);
    }

    return 0;
}