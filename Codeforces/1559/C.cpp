#include <iostream>

using namespace std;

bool isPointToHome[10010];

int main() {
    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int numOfVillage;
        cin >> numOfVillage;
        numOfVillage++;
        for (int i = 1; i < numOfVillage; i++) {
            int t;
            cin >> t;
            if (t == 0) isPointToHome[i] = true;
            else isPointToHome[i] = false;
        }

        if (!isPointToHome[1]) {
            cout << numOfVillage << ' ';
            for (int i = 1; i < numOfVillage; i++) cout << i << ' ';
            cout << endl;
        } else if (isPointToHome[numOfVillage - 1]) {
            for (int i = 1; i <= numOfVillage; i++) cout << i << ' ';
            cout << endl;
        } else {
            bool haveInterval = false;
            for (int i = 2; i < numOfVillage; i++) if (isPointToHome[i - 1] && !isPointToHome[i]) haveInterval = true;
            if (haveInterval) {
                bool isPut = false;
                cout << 1 << ' ';
                for (int i = 2; i < numOfVillage; i++) {
                    if (isPointToHome[i - 1] && !isPointToHome[i] && !isPut) {
                        isPut = true;
                        cout << numOfVillage << ' ';
                    }
                    cout << i << ' ';
                }
                cout << endl;
            } else cout << -1 << endl;
        }

    }

    return 0;
}