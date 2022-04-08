#include <iostream>

using namespace std;

int n;
int nums[100010];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        cin >> n;
        int odd = -1, even = -2;
        for (int i = 0; i < n; i++) cin >> nums[i];

        bool fail = false;
        for (int i = 0; i < n && !fail; i++) {
            if (nums[i] % 2 == 1) {
                if (odd > nums[i]) {
                    fail = true;
                    break;
                }
                odd = nums[i];
            } else {
                if (even > nums[i]) {
                    fail = true;
                    break;
                }
                even = nums[i];
            }
        }

        if(fail)    cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}