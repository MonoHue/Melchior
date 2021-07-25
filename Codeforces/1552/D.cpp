#include <iostream>
using namespace std;

const int OK = 999999999;

int n;
int num[500];

int solve(int cur, int sum, bool changed)  {
    if(sum == 0 && changed)    return OK;
    if(cur == n)   return -1;

    //cout << cur << "CURRENT NUM :  " << num[cur] << " SUM : " << sum << " USED : " << changed << endl;
    if(solve(cur + 1, sum + num[cur], true) == OK)   return OK;
    if(solve(cur + 1, sum - num[cur], true) == OK)   return OK;
    if(solve(cur + 1, sum, changed) == OK)  return OK;
    return -1;
}

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        cin >> n;
        for(int i = 0;i < n;i++)    cin >> num[i];

        if(solve(0, 0, false) == OK)   cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}