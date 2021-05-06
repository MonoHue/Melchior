#include <iostream>
#include <cstdio>
using namespace std;

int main()  {
#define int long long
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        int t, cnt = 0;
        cin >> t;
        int num[11] = {0,1,2,3,4,5,6,7,8,9};
        int generate[11] = {0,1,2,3,4,5,6,7,8,9};

        bool flag = true;
        while(flag) {
            for(int i = 1;i < 10;i++)   if(generate[i] <= t) cnt++;  else flag = false;
            for(int i = 1;i < 10;i++)   generate[i] = generate[i] * 10 + num[i];
        }

        cout << cnt << endl;
    }

    return 0;
}