#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> map;

int main()  {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)    {
        string tmp;
        cin >> tmp;
        map.emplace_back(tmp);
    }

    bool ok = true;
    for(int i = 0;ok && i < n;i++)    {
        ok = map[i][i] == '-';
    }

    for(int i = 0;ok && i < n;i++)  {
        for(int j = i + 1;ok && j < n;j++)  {
            if(map[i][j] == 'W')
                ok = map[j][i] == 'L';
            if(map[i][j] == 'L')
                ok = map[j][i] == 'W';
            if(map[i][j] == 'D')
                ok = map[j][i] == 'D';
        }
    }

    if(ok)
        cout << "correct" << endl;
    else
        cout << "incorrect" << endl;

    return 0;
}