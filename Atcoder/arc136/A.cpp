#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str, str1, ans;

int main()  {
    int n;
    scanf("%d", &n);
    cin >> str;
    for(auto c: str)    {
        if(c == 'A') { str1.push_back('B');str1.push_back('B'); }
        else str1.push_back(c);
    }

    for(int i = 0;i < str1.size();i++)  {
        if(str1[i] == 'B' && i + 1 < str1.size() && str1[i + 1] == 'B') {
            ans.push_back('A');
            i++;
            continue;
        }
        else ans.push_back(str1[i]);
    }

    cout << ans << endl;

    return 0;
}