#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int nums[200010];
int oddLoc[200010], evenLoc[200010], oddLen[200010], evenLen[200010];

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        cin >> n;
        for(int i = 1;i <= n;i++)
            cin >> nums[i];
        for(int i = 1;i <= n;i++)   {
            oddLoc[i] = 0;
            oddLen[i] = 0;
            evenLoc[i] = 0;
            evenLen[i] = 0;
        }

        for(int i = 1;i <= n;i++)   {
            int &val = nums[i];
            if(i % 2 == 0 && evenLoc[val] == 0)  {
                evenLoc[val] = i;
                evenLen[val]++;
            }
            if(i % 2 == 1 && oddLoc[val] == 0)    {
                oddLoc[val] = i;
                oddLen[val]++;
            }

            if((oddLoc[val] + i) % 2 == 1)    {
                oddLoc[val] = i;
                oddLen[val]++;
            }
            if((evenLoc[val] + i) % 2 == 1)    {
                evenLoc[val] = i;
                evenLen[val]++;
            }
        }

        for(int i = 1;i <= n;i++)
            cout << max(oddLen[i], evenLen[i]) << " ";
        cout << endl;

    }

    return 0;
}