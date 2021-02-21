#include <cstdio>
#include <queue>
using namespace std;

const int RANGE = 50050;

int n, cnt = 0;
int assign[RANGE];

struct cow{
    int no;
    int l;
    int r;
    bool operator < (cow a) const {
        if(l < a.l) return true;
        if(l == a.l && r < a.r) return true;
        return false;
    }
    bool operator > (cow a) const {
        if(l > a.l) return true;
        if(l == a.l && r > a.r) return true;
        return false;
    }
};

struct line{
    int end;
    int no;
    bool operator < (line a) const  {
        return end < a.end;
    }
    bool operator > (line a) const{
        return end > a.end;
    }
};

priority_queue<cow, vector<cow>, greater<cow> > cows;
priority_queue<line, vector<line>, greater<line> > lines;

int main()  {
    scanf("%d", &n);

    for(int i = 1;i <= n;i++)    {
        cow t;
        scanf("%d%d", &t.l, &t.r);
        t.no = i;
        cows.push(t);
    }

    while(!cows.empty())   {
        cow tmpcow = cows.top();
        cows.pop();

        //Mention the condition - Creating a new line
        if(lines.empty() || tmpcow.l <= lines.top().end)    {
            line tmpline;
            cnt++;
            assign[tmpcow.no] = cnt;
            tmpline.no = cnt;
            tmpline.end = tmpcow.r;
            lines.push(tmpline);
        }
        else    {
            line tmpline = lines.top();
            lines.pop();

            assign[tmpcow.no] = tmpline.no;
            tmpline.end = tmpcow.r;
            lines.push(tmpline);
        }
    }

    printf("%d\n", cnt);
    for(int i = 1;i <= n;i++)    printf("%d\n", assign[i]);

    return 0;
}