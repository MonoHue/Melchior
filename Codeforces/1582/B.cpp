#include <iostream>
using namespace std;

int n;
int zeroCnt, oneCnt;
long long ans = 0;

long long pow2[64];

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        cin >> n;
        zeroCnt = 0;
        oneCnt = 0;
        for(int i = 0;i < n;i++)    {
            int t;
            cin >> t;
            if(t == 0)  zeroCnt++;
            if(t == 1)  oneCnt++;
        }
        pow2[0] = 1;
        for(int i = 1;i <= 62;i++) pow2[i] = 2 * pow2[i - 1];

        cout << pow2[zeroCnt] * oneCnt << endl;

    }

    return 0;
}