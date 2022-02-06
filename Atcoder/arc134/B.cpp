#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int len, r = len, l = 0;
char minChar;
string str;

map<char, queue<int> > path;
map<char, int> cnt;

int main() {
    cin >> len >> str;

    for(auto c:str) cnt[c]++;

    r = len;
    while(l < r)    {
        for(char c = 'a'; c <= 'z';c++) {
            if(cnt[c] != 0) {
                minChar = c;
                break;
            }
        }

        if(str[l] == minChar)   {
            cnt[str[l]]--;
            l++;
            continue;
        }

        for(int i = r - 1;i > l;i--)    {
            if(str[i] == minChar)   {
                cnt[str[i]]--;
                cnt[str[l]]--;
                swap(str[i], str[l]);
                l++;
                r = i;
                break;
            }
            else cnt[str[i]]--;
        }
    }


    cout << str;


    return 0;
}