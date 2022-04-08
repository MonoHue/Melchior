#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
int a[5010], b[5010];

bool checkNo() {
    map<int, int> m;
    for (int i = 0; i < n; i++) m[b[i]]++;
    for (int i = 0; i < n; i++) {
        if (m[a[i]] <= 0) return true;
        else m[a[i]]--;
    }
    return false;
}

bool checkYes() {
    int tmp[5010];
    for (int i = 0; i < n; i++) tmp[i] = a[i];
    sort(tmp, tmp + n);
    for (int i = 0; i < n - 1; i++) if (tmp[i] == tmp[i + 1]) return true;
    return false;
}

int getRev(int *nums) {
    int rVal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]) rVal++;
        }
    }
    return rVal;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    if (checkNo()) printf("No\n");
    else if (checkYes()) printf("Yes\n");
    else {
        int rev = getRev(a);
        rev -= getRev(b);
        if (rev < 0) rev *= -1;
        if (rev % 2 == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}