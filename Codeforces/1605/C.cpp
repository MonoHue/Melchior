#include <iostream>
#include <cstdio>

using namespace std;

int len;
char str[1010000];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        scanf("%d", &len);
        scanf("%s", str);

        int ans = -1;
        bool found = false;
        for (int i = 0; i < len - 1 && !found; i++) {
            if (str[i] == str[i + 1] && str[i] == 'a') {
                found = true;
                ans = 2;
            }
        }
        for (int i = 0; i < len - 2 && !found; i++) {
            if (str[i] == str[i + 2] && str[i] == 'a') {
                found = true;
                ans = 3;
            }
        }
        for (int i = 0; i < len - 3 && !found; i++) {
            if (str[i] == str[i + 3] && str[i] == 'a' && str[i + 1] != str[i + 2]) {
                found = true;
                ans = 4;
            }
        }
        for (int i = 0; i < len - 6 && !found; i++) {
            if (str[i] == 'a' &&
                str[i + 1] == 'b' &&
                str[i + 2] == 'b' &&
                str[i + 3] == 'a' &&
                str[i + 4] == 'c' &&
                str[i + 5] == 'c' &&
                str[i + 6] == 'a') {
                found = true;
                ans = 7;
            } else if (str[i] == 'a' &&
                       str[i + 1] == 'c' &&
                       str[i + 2] == 'c' &&
                       str[i + 3] == 'a' &&
                       str[i + 4] == 'b' &&
                       str[i + 5] == 'b' &&
                       str[i + 6] == 'a') {

                found = true;
                ans = 7;
            }
        }

        cout << ans << endl;
    }

    return 0;
}