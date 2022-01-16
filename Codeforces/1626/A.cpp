#include <iostream>
#include <algorithm>

using namespace std;

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        string str;
        cin >> str;
        sort(str.begin(), str.end());

        cout << str << endl;
    }


    return 0;
}