#include <iostream>
#include <queue>

using namespace std;

class DisjointSet {
public:
    DisjointSet(int range);
    ~DisjointSet();
    int find(int a);
    void merge(int a, int b);

private:
    int *head = nullptr;
};

DisjointSet::~DisjointSet() {

}

DisjointSet::DisjointSet(int range) {
    head = new int[range];
    for(int i = 0;i < range;i++)    head[i] = i;
}

int DisjointSet::find(int a) {
    if(head[a] == a)    return a;
    else return head[a] = find(head[a]);
}

void DisjointSet::merge(int a, int b) {
    head[find(a)] = head[find(b)];
}

int main() {
    int n, t1, t2;
    DisjointSet Diana(1010), Mocha(1010);
    cin >> n >> t1 >> t2;
    while (t1-- > 0) {
        int v1, v2;
        cin >> v1 >> v2;
        Mocha.merge(v1, v2);
    }
    while (t2-- > 0) {
        int v1, v2;
        cin >> v1 >> v2;
        Diana.merge(v1, v2);
    }

    int cnt = 0;
    queue<pair<int, int>> output;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if ((Diana.find(i) != Diana.find(j)) && (Mocha.find(i) != Mocha.find(j))) {
                output.push(make_pair(i, j));
                Mocha.merge(i, j);
                Diana.merge(i, j);
                cnt++;
            }
        }

    cout << cnt << endl;
    while (!output.empty()) {
        pair<int, int> a = output.front();
        output.pop();
        cout << a.first << ' ' << a.second << endl;
    }

    return 0;
}