#include <iostream>
using namespace std;

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        int a, b, c;
        cin >> a >> b >> c;
        int sum = a + b + c;
        if(sum % 3 == 0)    cout << 0 << endl;
        else cout << 1 << endl;

    }

    return 0;
}