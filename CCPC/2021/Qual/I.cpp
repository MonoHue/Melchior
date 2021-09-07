#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int len;
char word[100010];

int main()  {
    int testcases;scanf("%d", &testcases);while(testcases --> 0)    {
        multiset<pair<int, int> >   mts;
        pair<int, int>  udlr;
        long long cnt = 0;
        scanf("%d", &len);
        scanf("%s", word);
        udlr.first = 0;udlr.second = 0;
        mts.insert(udlr);
        for(int i = 0;i < len;i++) {
            if (word[i] == 'U') udlr.first++;
            else if (word[i] == 'D') udlr.first--;
            else if (word[i] == 'L') udlr.second++;
            else if (word[i] == 'R') udlr.second--;
            mts.insert(udlr);
        }
        for (auto it = mts.begin(); it != mts.end(); ) {
            long long cntper = mts.count(*it);
            advance(it, cntper);
            cnt += (cntper - 1) * cntper / 2;
        }

        printf("%lld\n", cnt);

    }

    return 0;
}