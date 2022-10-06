#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> vec;
string work, ans;
vector<pair<int, int> > direct = {{0, 1},
                                  {1, 0},
                                  {1, 1},
                                  {0, -1},
                                  {-1, 0},
                                  {-1, -1},
                                  {-1, 1},
                                  {1, -1}};

int add(int loc, int diff) {
    return (loc + diff + n) % n;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        vec.emplace_back(tmp);
    }

    work = string(n, '0');
    ans = string(n, '0');

    char maxi = '0';
    for (const string &str: vec) {
        for (char c: str) {
            if (maxi < c)
                maxi = c;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for(auto d: direct)    {
                int x = i, y = j;
                int &dx = d.first, &dy = d.second;
                for(int loc = 0;loc < n;loc++)
                    work[loc] = vec[add(x, loc * dx)][add(y, loc * dy)];

                if(ans < work)
                    ans = work;
            }
        }
    }

    cout << ans << endl;

    return 0;
}