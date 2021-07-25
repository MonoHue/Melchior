#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int opposite[210];

struct order{
    int num;
    int belong;
};

bool cmp(order a, order b){
    return a.num < b.num;
};

bool check(int a, int opa, int b, int opb)  {
    order k[5];
    k[0].num = a;k[0].belong = 1;
    k[1].num = opa;k[1].belong = 1;
    k[2].num = b;k[2].belong = -1;
    k[3].num = opb;k[3].belong = -1;

    sort(k, k + 4, cmp);
    if(k[0].belong * k[1].belong < 0 && k[1].belong * k[2].belong < 0)   {
        //printf("OK : %d %d %d %d\n",a,opa,b,opb);
        return true;
    }
    return false;
}

int main()  {
    int testcases;cin >> testcases;while(testcases --> 0)   {
        int ans = 0;
        vector<int> a;
        cin >> n >> k;
        for(int i = 1;i <= 2 * n;i++)   opposite[i] = i;
        for(int i = 1;i <= k;i++)    {
            int t1, t2;
            cin >> t1 >> t2;
            opposite[t1] = t2;
            opposite[t2] = t1;
        }

        for(int i = 1;i <= 2 * n;i++)   if(opposite[i] == i)    a.push_back(i);
        for(int i = 0;i < a.size() / 2;i++)   {
            opposite[a[i]] = a[i + a.size() / 2];
            opposite[a[i + a.size() / 2]] = a[i];
        }

        for(int i = 1;i <= 2 * n;i++)   for(int j = 1;j <= 2 * n;j++)    {
            if(opposite[i] == j || i == j)    continue;
            if(opposite[i] > i || opposite[j] > j)   continue;
            if(check(i, opposite[i], j, opposite[j]))   ans++;
        }
        cout << ans / 2<< endl;
    }

    return 0;
}

/*
1
10 6
14 6
2 20
9 10
13 18
15 12
11 7
*/