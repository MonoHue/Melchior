#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int athletes[50010][5];

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        int n;
        cin >> n;
        for(int i = 0;i < n;i++)    for(int j = 0;j < 5;j++)    cin >> athletes[i][j];

        int win[5], winid = 0;
        for(int i = 0;i < 5;i++)    win[i] = athletes[0][i];

        for(int i = 1;i < n;i++)    {
            int wincnt = 0, icnt = 0;
            for(int j = 0;j < 5;j++)    {
                if(win[j] > athletes[i][j]) wincnt++;
                if(win[j] < athletes[i][j]) icnt++;
            }

            if(wincnt > icnt)   {
                for(int j = 0;j < 5;j++)    win[j] = athletes[i][j];
                winid = i;
            }
        }

        bool flag = true;
        for(int i = 0;i < n;i++)    {
            if(i == winid)  continue;
            int wincnt = 0, icnt = 0;
            for(int j = 0;j < 5;j++)    {
                if(win[j] > athletes[i][j]) wincnt++;
                if(win[j] < athletes[i][j]) icnt++;
            }

            if(wincnt > icnt)   {
                flag = false;
                cout << -1 << endl;
                break;
            }
        }
        if(flag)    cout << winid + 1 << endl;
    }

    return 0;
}