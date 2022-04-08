#include <iostream>

using namespace std;

const long long MOD = 998244353;
long long smallCnt = 0, equalCnt = 0;
int len;
long long cnt;
string str;

bool checkPal()    {
    int left = len / 2, right = len / 2;
    if(len % 2 == 0)    left--;
    while(left >= 0 && right < len)  {
        if(str[left] > str[right])  return false;
        if(str[left--] < str[right++])  return true;
    }
    return true;
}

long long getPow(int left)  {
    if(left == 1)   return 26;
    if(left == 0)   return 1;
    long long rVal = getPow(left / 2);
    rVal *= rVal;
    rVal %= MOD;
    if(left % 2 == 1)   rVal *= 26;
    return rVal % MOD;
}

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        cin >> len;
        cin >> str;
        cnt = 0;
        if(checkPal())   cnt++;

        int halfLen = (len + 1) / 2;
        for(int i = 0;i < halfLen;i++)  {
            cnt += (str[i] - 'A') * getPow(halfLen - i - 1);
            cnt %= MOD;
        }

        cout << cnt << endl;
    }

    return 0;
}