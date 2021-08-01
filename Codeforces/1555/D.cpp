#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int len, query, l, r;
char word[200010];
int prefix[6][200010];

int main()  {
    cin >> len >> query;
    scanf("%s", word);

    for(int i = 0;i < 3;i++)    {
        int cost = 0;
        for(int j = 0;j <= len;j++)    {
            prefix[i][j] = cost;
            char testchar;
            if((i + j) % 3 == 0)    testchar = 'a';
            if((i + j) % 3 == 1)    testchar = 'b';
            if((i + j) % 3 == 2)    testchar = 'c';
            if(word[j] != testchar) cost++;
        }
    }
    for(int i = 0;i < 3;i++)    {
        int cost = 0;
        for(int j = 0;j <= len;j++)    {
            prefix[i + 3][j] = cost;
            char testchar;
            if((i + j) % 3 == 0)    testchar = 'c';
            if((i + j) % 3 == 1)    testchar = 'b';
            if((i + j) % 3 == 2)    testchar = 'a';
            if(word[j] != testchar) cost++;
        }
    }

//    for(int i = 0;i < 6;i++)    {
//        for(int j = 0;j < len;j++)  cout << prefix[i][j] << " ";
//        cout << endl;
//    }

    while(query --> 0)  {
        cin >> l >> r;
        l--;
        r--;
        int mincost = 1000000000;
        for(int i = 0;i < 6;i++)    mincost = min(mincost, prefix[i][r + 1] - prefix[i][l]);

        cout << mincost << endl;
    }

    return 0;
}