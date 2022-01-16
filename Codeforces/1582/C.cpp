#include <iostream>
#include <cstdio>
using namespace std;

int n;
char word[100010];

int check(char c)   {
    bool ok = true;
    int cnt = 0;
    for(int i = 0, j = n - 1;i < j;i++, j--)    {
        int iAdd = 0,jAdd = 0;
        while(word[i + iAdd] == c && i + iAdd < j + jAdd)  iAdd ++;
        while(word[j + jAdd] == c && i + iAdd < j + jAdd)  jAdd --;
        cnt += iAdd - jAdd - 2 * min(iAdd, -jAdd);
        i += iAdd;
        j += jAdd;

        if(word[i] == c || word[j] == c)    {
            if(word[i] == c && word[j] == c)    {break;}
            else {cnt++;break;}
        }
        if(word[i] != word[j])  {ok = false;break;}

    }


    if(!ok) return 1e9;
    else return cnt;
}

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        cin >> n;
        scanf("%s", word);

        bool ok = true;
        for(int i = 0, j = n - 1; i < j;i++, j--)   {
            if (word[i] != word[j]) {ok = false;break;}
        }
        if(ok)  {
            cout << 0 << endl;
            continue;
        }

        int lower = 1e9;
        for(char c = 'a';c <= 'z';c++)  {
            lower = min(lower, check(c));
        }
        if(lower == 1e9)    cout << -1 << endl;
        else cout << lower << endl;
    }

    return 0;
}