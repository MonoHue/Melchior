#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int len, diff, ans;
bool arr[100010];

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        diff = 0;
        ans = 0;
        cin >> len;
        for(int i = 0;i < len;i++)  {
            int t;
            cin >> t;
            if (t % 2 == 0) {
                diff++;
                arr[i] = true;
            }
            else {
                diff--;
                arr[i] = false;
            }
        }

        if(diff == 1)   {
            int even = 0;
            for(int i = 0;i < len;i++)  {
                if(arr[i])  {
                    int add = i - 2 * even;
                    if(add < 0) add *= -1;
                    ans += add;
                    even++;
                }
            }

            cout << ans << endl;
        }
        else if(diff == -1) {
            int odd = 0;
            for(int i = 0;i < len;i++)  {
                if(!arr[i])  {
                    int add = i - 2 * odd;
                    if(add < 0) add *= -1;
                    ans += add;
                    odd++;
                }
            }

            cout << ans << endl;
        }
        else if(diff == 0)  {
            int odd = 0;
            int even = 0;
            int anseven = 0;
            int ansodd = 0;
            for(int i = 0;i < len;i++)  {
                if(arr[i])  {
                    int add = i - 2 * even;
                    if(add < 0) add *= -1;
                    anseven += add;
                    even++;
                }
                else    {
                    int add = i - 2 * odd;
                    if(add < 0) add *= -1;
                    ansodd += add;
                    odd++;
                }
            }

            cout << min(ansodd, anseven) << endl;
        }
        else {
            cout << -1 << endl;
        }

    }

    return 0;
}
