#include <iostream>

using namespace std;

const int SIZE = 62;
long long a, s;

long long pow2[SIZE];
bool pattern[SIZE];
bool targetPat[SIZE];

void make_pow2(){
    pow2[0] = 1;
    for(int i = 1;i < SIZE;i++) {
        pow2[i] = 2 * pow2[i - 1];
    }
};

void make_pattern(long long num, bool * pat)    {
    for(int i = 0;i < SIZE;i++) pat[i] = false;
    for(int i = SIZE - 1;i >= 0;i--)    {
        if(pow2[i] <= num) { pat[i] = true;num -= pow2[i]; }
        else pat[i] = false;
    }
}

int main()  {
    make_pow2();
    int testcases;cin>>testcases;while(testcases-->0)   {
        cin >> a >> s;
        if(2 * a > s)   {cout << "No" << endl;continue;}
        make_pattern(a, pattern);
        make_pattern(s - 2 * a, targetPat);

        bool fail = false;
        for(int i = 0;i < SIZE && !fail;i++) {
            if(pattern[i] && pattern[i] == targetPat[i])  {
                fail = true;
            }
        }

        if(fail)    cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}