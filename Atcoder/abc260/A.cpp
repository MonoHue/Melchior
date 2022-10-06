#include <iostream>

using namespace std;

int cnt[256];

int main()  {
    string str;
    cin >> str;
    for(auto c:str)
        cnt[c]++;

    bool found = false;
    for(int i = 'a';i <= 'z';i++)   {
        if(cnt[i] == 1) {
            cout << char(i) << endl;
            found = true;
            break;
        }
    }
    if(!found)
        cout << -1 << endl;

    return 0;
}