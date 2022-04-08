#include <iostream>

using namespace std;

int n;
int nums[510];
int pre[510], suf[510];
bool exist[510];

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        cin >> n;
        for(int i = 0;i < n;i++)    cin >> nums[i];

        int l = 0, r = 0;
        for(int i = 0;i < n;i++)    if(nums[i] != i + 1)    {
            l = i;
            for(int j = n - 1;j >= 0;j--)   {
                if(nums[j] == i + 1) {
                    r = j;
                    break;
                }
            }
            break;
        }

        for(int i = 0;i < (r - l + 1) / 2;i++)  {
            swap(nums[l + i], nums[r - i]);
        }

        for(int i = 0;i < n;i++)    cout << nums[i] << " ";
        cout << endl;

    }

    return 0;
}