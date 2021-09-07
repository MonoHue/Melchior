#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
    int val;
    bool direct;    //right is positive
}arr[1010];

int n;

int main()  {
    cin >> n;
    for(int i = 0;i < n;i++)    {
        cin >> arr[i].val;
        if(i % 2 == 0)
    }
    if(n % 2 == 1)  n--;

    return 0;
}
