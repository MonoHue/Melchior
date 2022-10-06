#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        long long len;
        string s;
        cin >> len >> s;
        for (int i = 1;i < s.size();i++)    {
            if(s[i - 1] != s[i])
                len += i;
        }

        cout << len << endl;
    }

    return 0;
}