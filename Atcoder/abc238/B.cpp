#include <iostream>

using namespace std;

bool mark[400];

int main()  {
    int n;
    cin >> n;
    int direction = 0;
    mark[0] = true;
    for (int i = 0;i < n;i++)   {
        int t;
        cin >> t;
        direction += t;
        direction %= 360;
        mark[direction] = true;
    }

    direction = 0;
    int ans = -1;
    for(int i = 0;i < 360;i++)  {
        if(mark[i]) {
            ans = max(i-direction, ans);
            direction = i;
        }
    }
    ans = max(360-direction, ans);

    cout << ans << endl;


    return 0;
}