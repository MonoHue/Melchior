#include <iostream>
#include <cstdio>
#define INI 'H'
using namespace std;

int main()  {
    int testcases;
    cin >> testcases;

    for(int tc = 1;tc <= testcases;tc++)    {
        int costx, costy, ans = 0;
        char str[1010];
        for(int i = 0;i < 1010;i++) str[i] = 0;

        scanf("%d%d%s", &costx, &costy, str);

        char fore = INI;

        for(int cursor = 0;str[cursor] != 0;cursor++) {
            bool noquestion = true;
            if(str[cursor] == '?')  noquestion = false;
            while(str[cursor] == '?')   cursor++;
            if(fore == INI) fore = str[cursor];
            if(fore == 'C' && str[cursor] == 'C')   {
                if(noquestion)  continue;
            }
            else if(fore == 'C' && str[cursor] == 'J')   {
                if(noquestion)  {
                    ans += costx;
                    fore = 'J';
                    continue;
                }
                ans += costx;
                fore = 'J';
            }
            else if(fore == 'J' && str[cursor] == 'C')   {
                if(noquestion)  {
                    ans += costy;
                    fore = 'C';
                    continue;
                }
                ans += costy;
                fore = 'C';
            }
            else if(fore == 'J' && str[cursor] == 'J')   {
                if(noquestion)  continue;
            }
        }

        printf("Case #%d: %d\n", tc, ans);
    }

    return 0;
}