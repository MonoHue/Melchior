#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char num[210000];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        scanf("%s", num);

        int len;
        for (int i = 0; i < 210000; i++)
            if (num[i] < '0' || num[i] > '9') {
                len = i;
                break;
            } else num[i] -= '0';

        bool found = false;
        for (int i = len - 1; i > 0; i--) {
            if (num[i] + num[i - 1] >= 10) {
                int t = num[i] + num[i - 1];
                found = true;
                num[i] = t % 10;
                num[i - 1] = 1;
                break;
            }
        }

        if (found) {
            for(int i = 0;i < len;i++)  cout << int(num[i]);
            cout << endl;
        } else {
            int t = num[0] + num[1];
            num[1] = t;

            for(int i = 1;i < len;i++)  cout << int(num[i]);
            cout << endl;
        }


    }


    return 0;
}