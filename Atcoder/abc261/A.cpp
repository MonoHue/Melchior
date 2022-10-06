#include <iostream>
#include <algorithm>

using namespace std;

int main()  {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    if(l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if(r1 > r2)
        cout << r2 - l2;
    else
        cout << max(0, r1 - l2);

    return 0;
}