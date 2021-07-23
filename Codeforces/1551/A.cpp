#include <iostream>
using namespace std;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        int num;
        cin >> num;
        if(num % 3 == 0)    cout << num / 3 << " " << num / 3 << endl;
        else if (num % 3 == 1)  cout << num / 3 + 1 << " " << num / 3 << endl;
        else if (num % 3 == 2)  cout << num / 3 << " " << num / 3 + 1 << endl;

    }

    return 0;
}