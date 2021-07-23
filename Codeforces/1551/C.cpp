#include <iostream>
using namespace std;

struct WORD{
    int a;
    int b;
    int c;
    int d;
    int e;
}word[200010];

int n;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        cin >> n;
        for(int i = 0;i < n;i++)    {
            word[i].a = 0;word[i].b = 0;word[i].c = 0;word[i].d = 0;word[i].e = 0;
            char text[500];
            scanf("%s", text);
        }
    }


    return 0;
}