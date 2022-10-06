#include <iostream>
#include <algorithm>

using namespace std;

int len, n, m;
string pattern;
pair<unsigned long long, unsigned long long> copyPaste[200010];

void read() {
    cin >> pattern;
    unsigned long long l, r;
    unsigned long long loc = pattern.size();
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        copyPaste[i].first = loc;
        copyPaste[i].second = l - 1;
        loc += r - l + 1;
    }
}

unsigned long long biSearch(unsigned long long val) {
    unsigned long long l = 0, r = n;
    while (r - l > 1) {
        unsigned long long mid = (l + r) / 2;
        if (copyPaste[mid].first <= val)
            l = mid;
        else r = mid;
    }
    return l;
}

unsigned long long where(unsigned long long loc) {
    if (loc < pattern.size())
        return loc;

    unsigned long long idx = biSearch(loc);
    return where(copyPaste[idx].second - copyPaste[idx].first + loc);
}

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        cin >> len >> n >> m;
        read();

        for (int i = 0; i < m; i++) {
            unsigned long long t;
            cin >> t;
            cout << pattern[where(t - 1)] << endl;
        }
    }

    return 0;
}