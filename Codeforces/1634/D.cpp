#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
const int pileLen = 4;
pair<int, int> pile[4];

int ask(int loc) {
    printf("?");
    for (auto &i: pile)
        if (i.second != loc) printf(" %d", i.second);
    cout << endl;

    int ret;
    cin >> ret;
    return ret;
}

void kick() {
    for (auto &i: pile) {
        i.first = ask(i.second);
    }
    sort(pile, pile + pileLen);
    pile[2].second = -1;
    pile[3].second = -1;
}

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        cin >> n;

        bool oddAsk = false;
        if (n % 2 == 1) {
            oddAsk = true;
            n++;
        }
        for (int i = 0; i < pileLen; i++) pile[i].second = i + 1;
        for (int i = pileLen; i < n; i += 2) {
            kick();
            pile[2].second = i + 1;
            pile[3].second = i + 2;
        }
        if (oddAsk) {
            bool ok = false;
            while (!ok) {
                ok = true;
                pile[3].second--;
                for (int i = 0; i < pileLen - 1; i++)
                    if (pile[3].second == pile[i].second) ok = false;
            }
        }
        kick();

        printf("! %d %d", pile[0].second, pile[1].second);
        cout << endl;
    }

    return 0;
}