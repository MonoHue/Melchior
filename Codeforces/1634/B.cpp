#include <iostream>

using namespace std;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        long long n, x, y;
        cin >> n >> x >> y;
        x %= 2;
        y %= 2;
        int oddCnt = 0;
        for(int i = 0;i < n;i++)    {
            int t;
            cin >> t;
            if(t % 2 == 1)  oddCnt++;
        }

        bool alice = true;
        if(x != y)  {
            if(oddCnt % 2 != 1) alice = false;
        }
        else    {
            if(oddCnt % 2 == 1) alice = false;
        }

        if(alice)   cout << "Alice" << endl;
        else cout << "Bob" << endl;


    }

    return 0;
}