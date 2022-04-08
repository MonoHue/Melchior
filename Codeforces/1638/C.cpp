#include <iostream>
using namespace std;

int n, minMissingNum = 1;
int nums[100010];
bool exist[100010];

void updateMMN()    {
    while(exist[minMissingNum]) minMissingNum++;
}


int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int ans = 0;
        cin >> n;
        for(int i = 0;i < n;i++)    cin >> nums[i];
        for(int i = 1;i <= n + 1;i++)    exist[i] = false;
        minMissingNum = 1;

        for(int i = 0;i < n;i++)    {
            exist[nums[i]] = true;
            updateMMN();
            if(minMissingNum == i + 2)  ans++;
        }

        cout << ans << endl;
    }
    return 0;
}