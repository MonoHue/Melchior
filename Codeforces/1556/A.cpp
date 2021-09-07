#include <iostream>
#include <cstdio>
using namespace std;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)   cout << 0 << endl;
        else if(a == b)  cout << 1 << endl;
        else if((a - b) % 2 == 0) cout << 2 << endl;
        else cout << -1 << endl;


    }

    return 0;
}
