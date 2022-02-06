#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0) {
        int n, k;
        cin >> n >> k;
        int oddCnt, evenCnt;
        oddCnt = evenCnt = n * k / 2;
        if(evenCnt * 2 != n * k)    oddCnt ++;

        if(oddCnt / k * k == oddCnt && evenCnt / k * k == evenCnt) {
            cout << "YES" << endl;
            for(int i = 0;i < n;i++)    {
                if(i % 2 == 0) {
                    for (int j = i * k + 1; j < i * k + 2 * k + 1; j+=2) cout << j << " ";
                    cout << endl;
                }
                else {
                    i--;
                    for (int j = i * k + 2; j < i * k + 2 * k + 2; j+=2) cout << j << " ";
                    i++;
                    cout << endl;
                }
            }
        }
        else    cout << "NO" << endl;
    }

    return 0;
}