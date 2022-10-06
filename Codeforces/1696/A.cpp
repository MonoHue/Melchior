#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int testcases;cin >> testcases;
    while (testcases --> 0) {
        int n, z;
        cin >> n >> z;
        int maxi = -1;
        while(n --) {
            int t;
            cin >> t;
            maxi = max(maxi, z | t);
        }

        cout << maxi << endl;

    }

    return 0;
}