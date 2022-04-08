#include <iostream>
#include <algorithm>

using namespace std;

int q;
string str;

char getNextChar(char c, int pos)   {
    if(c == 'A' && pos == 0)    return 'B';
    if(c == 'A' && pos == 1)    return 'C';
    if(c == 'B' && pos == 0)    return 'C';
    if(c == 'B' && pos == 1)    return 'A';
    if(c == 'C' && pos == 0)    return 'A';
    if(c == 'C' && pos == 1)    return 'B';
}

char getCurrent(long long t, long long k)   {
    if(t == 0)  return str[k];
    if(k == 0)  {
        char rc = str[k];
        t %= 3;
        while (t--) {
            rc++;
            if(rc > 'C')    rc = 'A';
        }
        return rc;
    }
    return getNextChar(getCurrent(t - 1, k / 2), k % 2);
}

int main()  {
    cin >> str;
    cin >> q;
    while(q-->0)    {
        long long t, k;
        cin >> t >> k;
        k--;

        char c = getCurrent(t, k);

        cout << c << endl;
    }

    return 0;
}