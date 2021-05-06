#include <iostream>
#include <cstdio>
using namespace std;

bool OK[1000];
char word[100];

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        int len;
        cin >> len;
        scanf("%s", word);

        for(int i = 'A';i <= 'Z';i++)   OK[i] = false;
        bool flag = true;
        for(int i = 0;i < len && flag;i++)  {
            while(i + 1 < len && word[i] == word[i + 1])    i++;
            if(OK[word[i]]) {
                printf("NO\n");
                flag = false;
            }
            else OK[word[i]] = true;
        }
        if(flag)    printf("YES\n");
    }


    return 0;
}