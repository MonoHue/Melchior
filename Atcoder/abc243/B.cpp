#include <iostream>
#include <set>

using namespace std;

int n;
int a[1010], b[1010];

int main()  {
    cin >> n;
    for(int i = 0;i < n;i++)    cin >> a[i];
    for(int i = 0;i < n;i++)    cin >> b[i];

    int cnt = 0;
    for(int i = 0;i < n;i++)    {
        if(a[i] == b[i])    cnt++;
    }
    cout << cnt << endl;

    set<int> sa(a, a + n), sb(b, b + n);

    cnt *= -1;
    for(auto num:sa)    {
        if(sb.find(num) != sb.end())    cnt++;
    }
    cout << cnt << endl;

    return 0;
}