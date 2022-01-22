#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
pair<int, int>  items[150];

bool cmp(pair<int, int> a, pair<int, int> b)    {
    return a.first < b.first;
}

int main() {
    int testcases;cin >> testcases;while (testcases-- > 0) {
        cin >> n >> k;
        for(int i = 0;i < n;i++)    cin >> items[i].first;
        for(int i = 0;i < n;i++)    cin >> items[i].second;

        sort(items, items + n,cmp);

        for(int i = 0;i < n;i++)    {
            if(k < items[i].first)  break;
            else k+=items[i].second;
        }

        cout << k << endl;
    }

    return 0;
}