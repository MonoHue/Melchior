#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int k;
    cin >> k;
    if (k >= 60)
        printf("22:%02d\n", k % 60);
    else
        printf("21:%02d\n", k % 60);

    return 0;
}