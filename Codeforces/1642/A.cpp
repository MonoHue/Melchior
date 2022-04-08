#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        pair<int, int> e[3];
        for(int i = 0;i < 3;i++)
            cin >> e[i].first >> e[i].second;

        sort(e, e + 3,
             [](pair<int, int> a, pair<int, int> b) -> bool {
            return a.second < b.second;
        });

        if(e[1].second == e[2].second)  cout << abs(e[1].first - e[2].first) << endl;
        else cout << 0 << endl;
    }

    return 0;

}

