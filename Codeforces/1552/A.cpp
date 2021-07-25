#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char str[50], str2[50];

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        int len;
        cin >> len;
        scanf("%s", str);

        for(int i = 0;i < len;i++)  str2[i] = str[i];

        sort(str, str + len);

        int sum = 0;
        for(int i = 0;i < len;i++)  if(str2[i] != str[i])   sum++;

        cout << sum << endl;
    }

    return 0;
}