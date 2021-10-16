#include <cstdio>
#include <iostream>
using namespace std;

int n;

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        cin >> n;

        for(int i = 0;i < n;i++) {
            for (int j = i; j < n; j++) printf("(");
            for (int j = i; j < n; j++) printf(")");
            for (int j = n - i; j < n; j++) printf("(");
            for (int j = n - i; j < n; j++) printf(")");
            printf("\n");
        }
    }

    return 0;
}