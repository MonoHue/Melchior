#include <iostream>
#include <cstdio>

using namespace std;

int pattern[4][4] = {{1, 0, 0, 1},
                     {0, 1, 1, 0},
                     {0, 1, 1, 0},
                     {1, 0, 0, 1}};

int ans[51][51];


int main() {
    for (int row = 0; row < 50; ++row)
        for (int col = 0; col < 50; ++col)
            ans[row][col] = pattern[row % 4][col % 4];

    int testcases;
    cin >> testcases;
    while (testcases-- > 0) {
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}