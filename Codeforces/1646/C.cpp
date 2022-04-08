#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long MAX = 1e12 + 10;

vector<long long> nums;
vector<long long> sums;

void make_vector()    {
    nums.emplace_back(1);
    nums.emplace_back(2);
    for(long long num = 4;num < MAX;num *= 2)   nums.push_back(num);
    long long fact = 4;
    for(long long num = 6;num < MAX;num *= fact++)  nums.push_back(num);
    sort(nums.begin(), nums.end());

    sums.push_back(nums[0]);
    for(int i = 1;i < nums.size();i++)  {
        sums.push_back(sums[i - 1] + nums[i]);
    }
}

int solve(long long num, int loc, int cnt)   {
    if(num == 0)    return cnt;
    if(num > sums[loc] || num < 0 || loc < 0) return 100000;

    int ret = 100000;
    for(int i = loc;sums[i] >= num && i >= 0;i--) {
        ret = min(ret, solve(num - nums[i], i - 1, cnt + 1));
    }
    return ret;
}

int main() {
    make_vector();
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        long long n;
        cin >> n;

        int ret = solve(n, nums.size() - 1, 0);
        if(ret == 100000)   cout << -1 << endl;
        else cout << ret << endl;
    }

    return 0;
}