#include <iostream>
#include <algorithm>

using namespace std;

int lastUpdated;
int n, mex, outputLoc;
int nums[2000010];
int output[2000010];
int cnt[2000010];
bool exist[2000010];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        cin >> n;
        for (int i = 0; i < n; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            cnt[nums[i]]++;
        }

        outputLoc = 0;
        for (int i = 0; i < n; i = lastUpdated + 1) {
            if (cnt[0] == 0) {
                while (i++ < n) output[outputLoc++] = 0;
                break;
            }

            mex = 0;
            while (cnt[mex] != 0) mex++;
            output[outputLoc++] = mex;

            int currentMex = 0;
            for (int j = 0; j <= mex; j++) exist[j] = false;
            for (int j = i; j < n; j++) {
                exist[nums[j]] = true;
                cnt[nums[j]]--;
                if (exist[0]) while (exist[currentMex]) currentMex++;
                if (currentMex == mex) {
                    lastUpdated = j;
                    break;
                }
            }

        }


        cout << outputLoc << endl;
        for (int i = 0; i < outputLoc; i++) cout << output[i] << " ";
        cout << endl;
    }

    return 0;
}