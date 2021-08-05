#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const char EMPTY = '0';
const char EXISTED = '1';
const char OCCUPIED = '2';

int cnt = 0;
char up[200010], down[200010];

bool checkmiddle(int x) {
    if(up[x] == EMPTY)    {
        cnt++;
        up[x] = OCCUPIED;
        return true;
    }
    return false;
}

bool checkleft(int x) {
    if(up[x - 1] == EXISTED)    {
        cnt++;
        up[x - 1] = OCCUPIED;
        return true;
    }
    return false;
}
bool checkright(int x) {
    if(up[x + 1] == EXISTED)    {
        cnt++;
        up[x + 1] = OCCUPIED;
        return true;
    }
    return false;
}
int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        int n;
        cnt = 0;

        cin >> n;
        scanf("%s", up);
        scanf("%s", down);

        for(int i = 0;i < n;i++)    {
            if(down[i] == EXISTED)  {
                if(i == 0) { if (!checkmiddle(i)) checkright(i); }
                else if(i == n - 1) { if (!checkleft(i)) checkmiddle(i); }
                else    {
                    if(!checkleft(i))   if(!checkmiddle(i)) checkright(i);
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}