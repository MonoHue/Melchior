#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int occur[300];
char word[10010];
char newword[10010];

int main() {
    int testcases;
    cin >> testcases;
    for (int cases = 1; cases <= testcases; cases++) {
        priority_queue<pair<int, char>, vector<pair<int, char> > > heap;
        priority_queue<pair<int, char>, vector<pair<int, char> > , greater<pair<int, char> > > heap_r;
        for (int i = 0; i < 300; i++) occur[i] = 0;
        for (int i = 0; i < 10010; i++) word[i] = 0;
        for (int i = 0; i < 10010; i++) newword[i] = 0;
        scanf("%s", word);

        for (int i = 0; word[i] != 0; i++) occur[word[i]]++;

        for (int i = 'a'; i <= 'z'; i++) {
            if (occur[i] != 0) heap.push(make_pair(occur[i], i));
        }

        bool fail = false;
        while (!heap.empty() && !fail) {
            auto p = heap.top();
            heap.pop();
            int freq = p.first;
            for (int i = 0; word[i] != 0 && freq > 0; i++) {
                if (newword[i] == 0 && word[i] != p.second) {
                    newword[i] = p.second;
                    freq--;
                }
            }
            if (freq > 0) fail = true;
        }

        if (fail) printf("Case #%d: IMPOSSIBLE\n", cases);
        else {
            printf("Case #%d: %s\n", cases, newword);
        }

    }

    return 0;
}
