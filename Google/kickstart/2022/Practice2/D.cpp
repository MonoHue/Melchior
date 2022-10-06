#include <iostream>
#include <map>

using namespace std;

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int main() {
    int testcases;
    cin >> testcases;
    for (int testcase = 1; testcase <= testcases; testcase++) {
        map<string, int> m;

        string str;
        cin >> str;

        int lastVowelLoc = -1;
        int cnt = 0;
        bool ok = false;

        for (int i = 0; !ok && i < str.size(); i++) {
            if (isVowel(str[i])) {
                cnt++;
                if (lastVowelLoc == -1) {
                    lastVowelLoc = i;
                    continue;
                }

                string slice = str.substr(lastVowelLoc, i - lastVowelLoc + 1);

                if (m[slice] != 0 && cnt - m[slice] > 2)
                    ok = true;
                else m[slice] = cnt;

                lastVowelLoc = i;
            }
        }


        if (ok)
            cout << "Case #" << testcase << ": " << "Spell!" << endl;
        else
            cout << "Case #" << testcase << ": " << "Nothing." << endl;
    }

    return 0;
}