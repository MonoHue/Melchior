/*
 * It's a fake solution.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int n, k;
long long ans = 0;
const int MAX_SIZE = 330;
const int MOD = 998244353;
bool selected[MAX_SIZE];
bool eligible[MAX_SIZE];
vector<int> precedence[MAX_SIZE];
pair<int, int> score[MAX_SIZE];

bool check_valid(int index) {
    if(eligible[index]) return true;

    for(auto node : precedence[index])  {
        if(!selected[node]) return false;
    }
    return true;
}

void dfs(int current, int cnt)  {
    if(cnt >= k) { ans ++;ans %= MOD;return;}
    if(current >= n)    return;

    for(int i = current + 1;i < n;i++)  {
        if(check_valid(i))  {
            selected[i] = true;
            dfs(i, cnt + 1);
            selected[i] = false;
        }
    }
}

int main()  {
    cin >> n >> k;
    for(int i = 0;i < n;i++)    cin >> score[i].first;
    for(int i = 0;i < n;i++)    cin >> score[i].second;
    sort(score, score + n, greater<>() );

    for(int i = 0;i < n;i++)    for(int j = 0;j < n;j++)
        if(score[i].first < score[j].first && score[i].second < score[j].second)    {
            precedence[i].push_back(j);
        }

    for(int i = 0;i < n;i++)    if(precedence[i].empty())   eligible[i] = true;

    dfs(-1, 0);

    cout << ans;


    return 0;
}