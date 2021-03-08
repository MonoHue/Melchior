//Different Set Maintenance
#include <iostream>
#include <cstdio>
#define RANGE 100010
using namespace std;

int n, m;
int father[2 * RANGE];

int find(int item) {
    if(item == father[item])    return item;
    else return father[item] = find(father[item]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if(a != b)  father[a] = b;
}

bool isOneSet(int a, int b) {
    return find(a) == find(b);
}

int main()  {
    int testcases;
    scanf("%d", &testcases);

    while(testcases --> 0)  {
        scanf("%d%d", &n, &m);
        for(int i = 1;i <= 2 * n;i++)   father[i] = i;

        while(m --> 0)  {
            char opt;
            int num1, num2;
            getchar();  //Catch '\n'
            scanf("%c%d%d", &opt, &num1, &num2);

            if(opt == 'D')  {
                merge(num1 + n, num2);
                merge(num1, num2 + n);
            }
            else    {
                if(isOneSet(num1, num2) || isOneSet(num1 + n, num2 + n)) cout << "In the same gang." << endl;
                else if(isOneSet(num1, num2 + n) || isOneSet(num1 + n, num2)) cout << "In different gangs." << endl;
                else cout << "Not sure yet." << endl;
            }
        }

    }


    return 0;
}