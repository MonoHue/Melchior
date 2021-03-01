#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long lossperturn = 0, ans = 0;
const int RANGE = 100010;   //Start from 2

struct cows{
    int time;
    int loss;
    double costratio;   //The index
}cow[RANGE];

bool cmp(cows a, cows b){
    return a.costratio > b.costratio;
}

int main()  {
    cin >> n;

    for(int i = 0;i < n;i++)    {
        scanf("%d%d", &cow[i].time, &cow[i].loss);
        lossperturn += cow[i].loss;
        cow[i].costratio = 1.0 * cow[i].loss / cow[i].time; //Minimize the loss
    }

    sort(cow, cow + n, cmp);

    for(int i = 0;i < n;i++)    {
        lossperturn -= cow[i].loss;
        ans += cow[i].time * 2 * lossperturn;
    }

    cout << ans;

    return 0;
}