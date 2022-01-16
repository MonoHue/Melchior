#include <iostream>
using namespace std;

int a, b, c;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        cin >> a >> b >> c;
        if((a + 2 * b + 3 * c) % 2 == 0)    cout << 0 << endl;
        else cout << 1 << endl;
    }

    return 0;

}