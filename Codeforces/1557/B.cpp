#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, k;
int nums[100010];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        scanf("%d%d", &n, &k);
        map<int, int> locate;
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
            locate[nums[i]] = i;
        }

        sort(nums, nums + n);
        int location = locate[nums[0]];
        for (int i = 1; i < n; i++) {
            int curLocation = locate[nums[i]];
//            cout << "DEBUG " << nums[i] << " " << curlocation << endl;
            if (curLocation == location + 1) location++;
            else {
//                cout << "FAILED " << location << endl;
                location = curLocation;
                k--;
            }
        }

        if (k > 0) cout << "Yes" << endl;
        else cout << "No" << endl;

    }

    return 0;
}