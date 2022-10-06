#include <iostream>
#include <vector>

using namespace std;

int abet[100010][30];

void abet_init(int size) {
    for(int i = 0;i < size;i++)
        for(int j = 0;j < 26;j++)
            abet[i][j] = 0;
}

int main()  {
    int testcases;cin >> testcases;
    for(int testcase = 1;testcase <= testcases;testcase++)  {
        int n, q, ans = 0;
        string str;
        cin >> n >> q;
        cin >> str;

        abet_init(str.size());

        for(int loc = 1;loc <= str.size();loc++)   {
            for(int i = 0;i < 26;i++)
                abet[loc][i] = abet[loc - 1][i];

            abet[loc][str[loc - 1] - 'A']++;
        }

        while(q--)  {
            int a, b;
            cin >> a >> b;
            int cnt = 0;
            for(int i = 0;i < 26;i++)
                if((abet[b][i] - abet[a - 1][i]) % 2 == 1)
                    cnt++;

            if(cnt <= 1)    ans++;
        }

        cout << "Case #" << testcase << ": " << ans << endl;
    }

    return 0;
}