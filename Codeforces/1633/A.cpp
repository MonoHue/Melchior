#include <iostream>
#include <vector>

using namespace std;

int compare(int a, int b)   {
    int cnt = 0;
    if(a / 100  == 0 && b / 100 == 0)   {
        while(a > 0 && b > 0)   {
            if(a % 10 != b % 10)    cnt++;
            a /= 10;
            b /= 10;
        }
    }
    else if(a / 100 == 0 || b / 100 == 0)   return 1000;
    else {
        while(a > 0 && b > 0)   {
            if(a % 10 != b % 10)    cnt++;
            a /= 10;
            b /= 10;
        }
    }
    return cnt;
}

vector<int> able;

int main()  {
    for(int i = 10;i < 1000;i++)
        if(i % 7 == 0)  able.push_back(i);

    int testcase;cin >> testcase;
    while (testcase-->0)    {
        int n;
        cin >> n;

        int ans = 10000;
        int number;
        for(auto num : able)    {
            if(ans > compare(n, num))   {
                ans = compare(n, num);
                number = num;
            }
        }

        cout << number << endl;
    }

    return 0;
}