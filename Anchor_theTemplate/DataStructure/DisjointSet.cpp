/*
 *
 *
 *
 *
 * */

class DisjointSet {
public:
    DisjointSet(int range);

    ~DisjointSet();

    int find(int a);

    void merge(int a, int b);

private:
    int *head = nullptr;
};

DisjointSet::DisjointSet(int range) {
    head = new int[range];
    for (int i = 0; i < range; i++) head[i] = i;
}

DisjointSet::~DisjointSet() {
    delete(head);
}

int DisjointSet::find(int a) {
    if (head[a] == a) return a;
    else return head[a] = find(head[a]);
}

void DisjointSet::merge(int a, int b) {
    head[find(a)] = head[find(b)];
}