#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<string> normal;
vector<string> express;

int main()  {
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)    {
        string str;
        cin >> str;
        normal.push_back(str);
    }
    for(int i = 0;i < m;i++)    {
        string str;
        cin >> str;
        express.push_back(str);
    }
    express.push_back(" ");

    int loc = 0;
    for(string str : normal)    {
        if(str == express[loc]) {
            cout << "Yes" << endl;
            loc++;
        }
        else cout << "No" << endl;
    }


    return 0;
}

