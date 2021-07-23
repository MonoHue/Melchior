#include <iostream>
#include <set>
using namespace std;

int n, k;
int nums[200010], occur[200010];



int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        cin >> n >> k;
        set<int> kset[k];

        for(int i = 0;i < n;i++)    cin >> nums[i];
        for(int i = 0;i < n;i++)    occur[i] = 0;
        for(int i = 0;i < n;i++)    {
            if(occur[nums[i]] >= k) continue;
            occur[nums[i]]++;

        }




    }

    return 0;
}