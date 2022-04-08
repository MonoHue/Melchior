#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool check(const vector<int> &nums) {
    set<int> s;
    for (int num: nums) {
        auto it = s.find(num);
        if (it == s.end()) s.insert(num);
        else s.erase(it);
    }

    return s.empty();
}

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int n;
        vector<int> nums;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            nums.emplace_back(t);
        }

        if (!check(nums)) cout << -1 << endl;
        else {
            int realLoc = 0;
            vector<int> lens;
            vector<pair<int, int> > opts;
            while (!nums.empty()) {
                int loc = 0;
                for (int i = 1; i < nums.size(); i++) {
                    if (nums[i] == nums[0]) {
                        loc = i;
                        realLoc += loc + 1;
                        break;
                    }
                }
                for (int i = 1; i < loc; i++) opts.emplace_back(realLoc++, nums[i]);

                reverse(nums.begin() + 1, nums.begin() + loc);
                nums.erase(nums.begin() + loc);
                nums.erase(nums.begin());
                lens.emplace_back(2 * loc);
            }

            cout << opts.size() << endl;
            for_each(opts.cbegin(), opts.cend(),
                     [](pair<int, int> p) { cout << p.first << " " << p.second << endl; });
            cout << lens.size() << endl;
            for_each(lens.cbegin(), lens.cend(),
                     [](int len) { cout << len << " "; });
            cout << endl;
        }
    }

    return 0;
}