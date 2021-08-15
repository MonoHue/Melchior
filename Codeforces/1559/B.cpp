#include <iostream>
#include <cstdio>

using namespace std;

char readin[101];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int n;
        cin >> n;
        scanf("%s", readin);
        bool havech = false;

        for (int i = 0; i < n; i++)
            if (readin[i] != '?') {
                for (int j = i - 1; j >= 0; j--) {
                    if (readin[j + 1] == 'R') readin[j] = 'B';
                    else readin[j] = 'R';
                }
                havech = true;
                break;
            }

        if (havech)
            for (int i = 0; i < n; i++) {
                if (readin[i] == '?') {
                    if (readin[i - 1] == 'B') readin[i] = 'R';
                    else readin[i] = 'B';
                }
            }
        else
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) readin[i] = 'R';
                else readin[i] = 'B';
            }

        for (int i = 0; i < n; i++) putchar(readin[i]);
        putchar('\n');
    }

    return 0;
}