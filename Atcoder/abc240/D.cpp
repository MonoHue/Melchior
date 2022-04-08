#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    stack<pair<int, int> > s;
    while (n-- > 0) {
        int t;
        scanf("%d", &t);
        cnt++;

        if (s.empty()) {
            s.push(make_pair(t, 1));
            printf("1\n");
        } else {
            if (s.top().first == t) {
                auto tmp = s.top();
                s.pop();
                tmp.second++;
                if (tmp.first == tmp.second) {
                    cnt -= tmp.second;
                }
                else s.push(tmp);
                printf("%d\n", cnt);
            }
            else {
                s.push(make_pair(t, 1));
                printf("%d\n", cnt);
            }
        }
    }


    return 0;
}