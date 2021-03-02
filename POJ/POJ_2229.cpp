#include <iostream>
using namespace std;

long long n, ans = 0;
long long twopowers[40];

//TODO: Algorithm Design
long long solve(long long a)   {
    ans += solve(a);

}



int main()  {
    cin >> n;

    int temp = 1;
    for(int i = 0;temp < 1000000;i++)   {
        twopowers[i] = temp;
        temp *= 2;
        cout << twopowers[i] << " ";
    }

    //solve(n);

    cout << ans;

    return 0;
}