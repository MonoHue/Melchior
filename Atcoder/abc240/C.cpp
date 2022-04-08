#include <iostream>
#include <cstdio>

using namespace std;

int n, x;
int choice[110][2];
bool dp[10010][2];

int main()  {
    cin >> n >> x;
    for(int i = 0;i < n;i++)    {
        cin >> choice[i][0] >> choice[i][1];
    }
    dp[0][1] = true;
    for(int i = 0;i < n;i++)    {
        for(int j = 0;j <= x;j++)   dp[j][i % 2] = false;
        for(int j = 0;j <= x;j++)    {
            if(dp[j][(i + 1) % 2])  {
                dp[j + choice[i][0]][i % 2] = true;
                dp[j + choice[i][1]][i % 2] = true;
            }
        }
    }

    if(dp[x][(n - 1) % 2])   cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}