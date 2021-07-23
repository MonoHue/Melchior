#include <iostream>
#include <cstdio>
using namespace std;

int occur[200];

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        for(int i = 0;i < 200;i++)  occur[i] = 0;
        char word[60];
        scanf("%s", word);
        for(int i = 0;word[i] != 0;i++) occur[word[i]]++;
        for(int i = 0;i < 200;i++)  if(occur[i] > 2)    occur[i] = 2;

        int sum = 0;
        for(int i = 0;i < 200;i++)  sum += occur[i];
        cout << sum/2 << endl;
    }

    return 0;
}