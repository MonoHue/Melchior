#include <iostream>
#include <cstdio>

using namespace std;

int main()  {
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    if(m >= x)
        cout << t << endl;
    else cout << t - (x - m) * d << endl;

    return 0;
}