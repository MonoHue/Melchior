#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = a + b + c + d;
        if (sum == 0) cout << 0 << endl;
        else if (sum <= 3)   cout << 1 << endl;
        else if (sum == 4)  cout << 2 << endl;
    }


    return 0;
}