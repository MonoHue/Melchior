#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool check(const string &a, const string &b) {
    string str = a + b;
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    return str == revStr;
}

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int n;
        cin >> n;

        bool trivial = false;
        bool paired = false;
        map<string, set<string> > edges;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;

            if (trivial || paired) continue;
            if (str.length() == 1) trivial = true;
            else if (str.length() == 2) {
                if (str[0] == str[1]) trivial = true;

                edges[str].insert(str);

                string key = str;
                reverse(key.begin(), key.end());
                for (const string &foreStr: edges[key]) {
                    if (check(foreStr, str)) {
                        paired = true;
                        break;
                    }
                }
            } else if (str.length() == 3) {
                if (str[0] == str[2]) trivial = true;

                edges[str.substr(0, 2)].insert(str);
                edges[str.substr(1, 2)].insert(str);

                string key = str.substr(0, 2);
                reverse(key.begin(), key.end());
                for (const string &foreStr: edges[key]) {
                    if (check(foreStr, str)) {
                        paired = true;
                        break;
                    }
                }
                key = str.substr(1, 2);
                reverse(key.begin(), key.end());
                for (const string &foreStr: edges[key]) {
                    if (check(foreStr, str)) {
                        paired = true;
                        break;
                    }
                }
            }
        }

        if (trivial || paired) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}