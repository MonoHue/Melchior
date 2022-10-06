#include <iostream>
#include <cstdio>

using namespace std;

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        int num;
        cin >> num;
        if(num%2==1)    cout << -1 << endl;
        else cout << num / 2 << " " << 0 << " " << 0 << endl;

    }

    return 0;
}