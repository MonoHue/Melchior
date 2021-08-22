#include <iostream>
#include <cstdio>
using namespace std;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        int n, k;
        cin >> n >> k;
        if(n == k)  {
            if(k <= 2)  cout << "No!" << endl;
            else cout << "Yes!" << endl;
        }
        else if (k % 2 == 1)    cout << "Yes!" << endl;
        else cout << "No!" << endl;
    }

    return 0;
}
