#include <cstdio>
#include <iostream>
using namespace std;

const long long MOD = 998244353;

long long power(long long a,long long b,long long c){
    long long ans = 1;
    long long base = a%c;
    while(b){
        if(b & 1) ans = (ans*base)%c;
        base = (base*base)%c;
        b >>= 1;
    }
    return ans;
}

int main()  {
    int testcases;cin >> testcases;while(testcases--) {
        long long a, b, k;
        bool flag = false;
        cin >> a >> b >> k;
        if(k == 0)  {cout << a << " " << b << endl;continue;}

        long long k1=power(2,k/2,MOD),k2=power(2,(k-1)/2,MOD);
        if(k%2)
        {
            cout<<(k2*((a+b)%MOD))%MOD<<" "<<(k2*((a-b+MOD)%MOD))%MOD<<endl;
        }
        else
        {
            cout<<(k1*a)%MOD<<" "<<(k1*b)%MOD<<endl;
        }
    }

    return 0;
}