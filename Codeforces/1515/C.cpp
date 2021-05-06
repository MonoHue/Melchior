#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct tower{
    int no;
    long long sum;
    friend bool operator < (const tower &a, const tower &b)  {
        return a.sum >= b.sum;
    }
    friend bool operator > (const tower &a, const tower &b)  {
        return a.sum <= b.sum;
    }
};

struct brick{
    int no;
    long long val;
    int tower;
}bricks[100100];

bool cmp1(brick a, brick b)  {
    return a.val > b.val;
}

bool cmp2(brick a, brick b) {
    return a.no < b.no;
}

int main()  {
    int testcases;
    cin >> testcases;
    while(testcases --> 0)  {
        long long n, m, heightdiff;
        priority_queue<tower, vector<tower> >   towerheap;

        //Readin
        cin >> n >> m >> heightdiff;
        for(int i = 1;i <= n;i++)   {
            scanf("%lld", &bricks[i].val);
            bricks[i].no = i;
            bricks[i].tower = 0;
        }

        //Make Heap
        for(int i = 1;i <= m;i++)   {
            tower t;
            t.no = i;t.sum = 0;
            towerheap.push(t);
        }

        sort(bricks + 1, bricks + n + 1, cmp1);

        for(int i = 1;i <= n;i++)    {
            tower t = towerheap.top();
            towerheap.pop();
            bricks[i].tower = t.no;
            t.sum += bricks[i].val;
            towerheap.push(t);
        }

        sort(bricks + 1, bricks + n + 1, cmp2);

        //Never NO
        printf("YES\n");
        for(int i = 1;i <= n;i++)   printf("%d ", bricks[i].tower);
        printf("\n");
    }

    return 0;
}