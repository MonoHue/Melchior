#include <iostream>

using namespace std;

const int SIZE = 250;
int isPrime[SIZE];

int main()  {
    isPrime[2] = true;
    for(int i = 3;i < SIZE;i++) isPrime[i] = true;
    for(int i = 3;i < SIZE;i++) {
        for(int j = 2;j * j <= i;j++)   {
            if(i % j == 0) {
                isPrime[i] = false;
                break;
            }
        }
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int taka = false;
    for(int i = a;i <= b && !taka;i++)   {
        taka = true;
        for(int j = c;j <= d;j++)   {
            if(isPrime[i + j])  {
                taka = false;
                break;
            }
        }
    }

    if(taka)    cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}