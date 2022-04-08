#include <iostream>
#include <set>

using namespace std;

set<pair<int, int> > a;

int direct[][2] = {
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1},
        {1, 2},
        {-1, 2},
        {1, -2},
        {-1, -2},
};

int main()  {
    int x, y;
    cin >> x >> y;

    for(auto dir:direct)    {
        a.insert(make_pair(x + dir[0], y + dir[1]));
    }

    cin >> x >> y;
    bool found = false;
    for(auto dir:direct)    {
        if(a.find(make_pair(x + dir[0], y + dir[1])) != a.end())    {
            found = true;
            break;
        }
    }

    if(found) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}