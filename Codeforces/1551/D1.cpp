#include <iostream>
using namespace std;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        int n, m, k;
        cin >> n >> m >> k;

        if(m % 2 == 1) if(n * m - n < k * 2)    {cout << "NO" << endl;continue;}
        if(n % 2 == 1)  {
            if(k < m / 2)   {cout << "NO" << endl;continue;}
            k -= m / 2;
        }

        if(k % 2 == 1)  {cout << "NO" << endl;continue;}

        cout << "YES" << endl;

    }

    return 0;
}