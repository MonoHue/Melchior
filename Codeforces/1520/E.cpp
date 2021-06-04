//TODO: Make this work

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        long long len, ans = 0, cnt = 0;
        char word[150000];
        scanf("%lld", &len);
        scanf("%s", word);

        for(int i = 0;i < len;i++)  if(word[i] == '*')  cnt++;
        int tempcnt = 0, midlocation;
        for(int i = 0;tempcnt < (cnt + 1)/2;i++)  if(word[i] == '*')  {
            tempcnt++;
            if(tempcnt == (cnt + 1)/2)    midlocation = i;
        }

        int leftcount = 0, rightcount = 0;
        if(midlocation <= len - 2)  for(int i = midlocation + 1;i < len;i++)    if(word[i] == '*')  {
            rightcount++;
            ans += i - midlocation - rightcount;
        }
        if(midlocation >= 1)    for(int i = midlocation - 1;i >= 0;i--)    if(word[i] == '*')  {
            leftcount++;
            ans += midlocation - i - leftcount;
        }

        printf("%lld\n", ans);
    }

    return 0;
}