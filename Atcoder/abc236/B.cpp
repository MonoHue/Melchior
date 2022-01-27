#include <iostream>

using namespace std;

int cnt[100010];

int main()  {
    int n;
    cin >> n;
    for(int i = 0;i < (4 * n) -1;i++)    {
        int t;
        cin >> t;
        cnt[t]++;
    }
    for(int i = 1;i <= n;i++)    {
        if(cnt[i] != 4) {
            cout << i << endl;
            break;
        }
    }




    return 0;
}

