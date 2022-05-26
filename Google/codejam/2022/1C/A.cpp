#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    for (int testcase = 1; testcase <= testcases; testcase++) {
        int n;
        cin >> n;
        string ans;
        vector<string> vec;
        map<char, unsigned long long> wild;
        while (n--) {
            string tmp;
            cin >> tmp;
            if (all_of(tmp.begin(), tmp.end(),
                       [tmp](char c) { return c == *tmp.begin(); }))
                wild[*tmp.begin()] += tmp.size();
            else vec.emplace_back(tmp);
        }

        if (vec.empty()) {
            for (auto key: wild)
                ans.append(key.second, key.first);
        } else {
            ans = vec[0];
            vec.erase(vec.begin());
            bool tmp = true;
            while (tmp) {
                tmp = false;
                char pat = *(ans.end() - 1);
                for (auto it = vec.begin(); it != vec.end(); it++) {
                    if ((*it)[0] == pat) {
                        if(wild[pat] > 0)   {
                            ans.append(wild[pat], pat);
                            wild[pat] = 0;
                        }
                        ans.append(*it);
                        vec.erase(it);
                        tmp = true;
                        break;
                    }
                }
            }
            tmp = true;
            while (tmp) {
                tmp = false;
                char pat = *(ans.begin());
                for (auto it = vec.begin(); it != vec.end(); it++) {
                    if (*((*it).end() - 1) == pat) {
                        if(wild[pat] > 0)   {
                            ans.append(wild[pat], pat);
                            wild[pat] = 0;
                        }
                        ans.append(*it);
                        vec.erase(it);
                        tmp = true;
                        break;
                    }
                }
            }





        }


    }

    return 0;
}