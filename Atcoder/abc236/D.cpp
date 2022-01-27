#include <iostream>

using namespace std;

int n;
int mapp[30][30];
int set[20];
bool attend[20];
int ans = -1;

void calculate(){
    int tmp = 0;
    for(int i = 0;i < 2 * n;i += 2) {
        tmp ^= mapp[set[i] - 1][set[i + 1] - set[i] - 1];
    }
    ans = max(ans, tmp);
};

void solve(int pos, int last)   {
    if(pos >= 2 * n)    return calculate();

    for(int i = last + 1;i <= 2 * n;i++) {
        if(!attend[i])  {
            attend[i] = true;
            set[pos] = i;
            for(int j = i + 1;j <= 2 * n;j++) {
                if(!attend[j])  {
                    attend[j] = true;
                    set[pos + 1] = j;
                    //for(int i = 0;i < 2 * n;i++)    cout << set[i] << " ";
                    //cout << endl;
                    solve(pos + 2, i);
                    attend[j] = false;
                }
            }
            attend[i] = false;
        }
    }
}

int main()  {
    cin >> n;
    for(int i = 0;i < (2 * n) - 1;i++)
        for(int j = 0;j < (2 * n - 1 - i);j++)
            cin >> mapp[i][j];

    for(int i = 0;i < 20;i++)   attend[i] = false;

    attend[0]=true;
    solve(0, 0);

    cout << ans;

    return 0;
}

