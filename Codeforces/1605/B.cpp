#include <iostream>
#include <cstdio>
using namespace std;

int n;
char num[1010];
bool selected[1010];

int main()  {
    int testcases;cin >> testcases;while(testcases-->0) {
        for (int i = 0;i < 1010;i++) selected[i] = false;

        scanf("%d", &n);
        scanf("%s", num);
        int front = 0, back = n - 1;
        int kcnt = 0;
        while(num[front] == '0')   front++;
        while(num[back] == '1')   back--;
        while(front < back) {
            selected[front++] = true;
            selected[back--] = true;
            kcnt += 2;
            while(num[front] == '0')   front++;
            while(num[back] == '1')   back--;
        }

        if(kcnt == 0)   cout << 0 << endl;
        else {
            cout << 1 << endl;
            cout << kcnt;
            for(int i = 0;i < n;i++)    if(selected[i]) cout << " " << i + 1;
            cout << endl;
        }
    }

    return 0;
}