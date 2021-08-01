#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int m;

struct LINE{
    int val;
    int pre;
    int suf;
}line[2][100010];;


int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        cin >> m;
        for(int i = 0;i < m;i++)    cin >> line[0][i].val;
        for(int i = 0;i < m;i++)    cin >> line[1][i].val;

        for(int i = 0;i < 2;i++)    {
            int tpre = 0, tsuf = 0;
            for(int j = 0;j < m;j++)    {
                line[i][j].pre = tpre;
                tpre += line[i][j].val;
            }
            for(int j = m - 1;j >= 0;j--)    {
                line[i][j].suf = tsuf;
                tsuf += line[i][j].val;
            }
        }

        int minans = 1000000000;
        for(int i = 0;i < m;i++)    {
            minans = min(minans, max(line[0][i].suf, line[1][i].pre));
        }

        cout << minans << endl;
    }

    return 0;
}