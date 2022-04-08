#include <iostream>
#include <cstdio>

using namespace std;

int a, b, c, x;

int main()  {
    cin >> a >> b >> c >> x;

    if(x <= a)  cout << 1 << endl;
    else if(x > b)  cout << 0 << endl;
    else cout << 1.0 * c / (b - a) << endl;



    return 0;
}