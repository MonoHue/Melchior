#include <iostream>
#include <algorithm>

using namespace std;

long long num, accum, lastLocation, lastHealth, accumLocation;
long long ans;
pair<int , int> monster[200];

inline int health(int i) {
    return monster[i].second;
}

inline int advent(int i) {
    return monster[i].first;
}

inline void updateAnswer() {
    ans += accum * (accum + 1) / 2;
    accum = 0;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        cin >> num;
        for (int i = 0; i < num; i++) cin >> monster[i].first;
        for (int i = 0; i < num; i++) cin >> monster[i].second;
        sort(monster, monster + num, cmp);

        ans = 0;
        accum = 0;
        accumLocation = 2e9;
        lastLocation = 2e9;
        lastHealth = 0;
        for (int i = num - 1; i >= 0; i--) {
            if (accumLocation - accum >= advent(i)) {
                updateAnswer();
                accum = health(i);
                accumLocation = advent(i);
            } else {
                accum += max(0, int(health(i) + accumLocation - advent(i) - accum));
            }
            lastHealth = health(i);
            lastLocation = advent(i);

            if (i == 0) updateAnswer();
        }

        cout << ans << endl;
    }

    return 0;
}