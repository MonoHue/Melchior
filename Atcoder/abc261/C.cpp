#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;

int main()  {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)    {
        string str;
        cin >> str;

        if(m[str] == 0)
            cout << str << endl;
        else
            cout << str << '(' << m[str] << ')' << endl;

        m[str] ++;
    }

    return 0;
}