#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()  {
    int n;
    cin >> n;
    set<int> s;

    while(n --> 0)  {
        int t;
        cin >> t;
        s.insert(t);
    }

    cout << s.size();


    return 0;
}