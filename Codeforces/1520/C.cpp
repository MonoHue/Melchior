#include <iostream>
#include <cstdio>
using namespace std;

int curi, curj, sizee;
int mapp[101][101];

void addmapp(int num)   {
    if(curi > sizee) {
        curi = 1;
        curj++;
    }
    mapp[curi][curj] = num;
    curi++;
}

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        curi = 1;curj = 1;
        cin >> sizee;
        if(sizee ==  1)  printf("1\n");
        else if (sizee == 2) printf("-1\n");
        else {
            for(int i = 1;i <= sizee * sizee;i += 2)   addmapp(i);
            for(int i = 2;i <= sizee * sizee;i += 2)   addmapp(i);
            for(int i = 1;i <= sizee;i++)    {
                for(int j = 1;j <= sizee;j++)    printf("%d ", mapp[i][j]);
                printf("\n");
            }
        }
    }

    return 0;
}