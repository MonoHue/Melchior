//Wrong Answer!
#include <iostream>
#include <vector>
using namespace std;

int nums[200010];
vector<int> primes{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,
                    101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,
                    223,227,229,233,239,241,251,257,263,269,271,277,281,
                    283,293,307,311,313,317,331,337,347,349,
                    353,359,367,373,379,383,389,397,401,409,
                    419,421,431};

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        int n;
        cin >> n;
        for(int i = 0;i < n;i++)    cin >> nums[i];

        int maxSet = 0;
        for(auto prime : primes )   {
            int cnt[100];
            for(int i = 0;i < prime - 1;i++)    cnt[i] = 0;

            int consecutive = 0;
            int pre = 0;
            for(int i = 0;i < n;i++)    {
                if(pre != (nums[i] % prime))    {
                    pre = nums[i] % prime;
                    maxSet = max(maxSet, consecutive);
                    consecutive = 0;
                }
                consecutive++;
            }
            maxSet = max(maxSet, consecutive);
        }

        cout << maxSet << endl;
    }

    return 0;
}