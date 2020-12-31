/*
 *  Disjoint Set
 *  Todo:   Merge by Rank[]
 *          Implementations
 *          Comments
 *          Descriptions
 *
 *  An ADT to check whether two elements are in the same set.
 *  There are two kinds of Disjoint Set Implementation:
 *      a.  Path Splitting
 *          It reduces the depth of the tree, giving findroot() lower time complexity.
 *          parent[] will be directed to the root of the element instead of the parent of the element.
 *          You will lose rank[] and the REAL parent.
 *      b.  Merge by Rank[]
 *          It records the depth of every element in the tree, according to the sequence of operations.
 *          You can choose to attach the smaller tree to the larger tree to reduce the overall depth, but it will ruin the sequence of operations.
 *
 *  Required Header File:
 *      None.
 *
 *  Prerequisite:
 *      const int RANGE
 *          Declare the MAX quantity of elements.
 *
 *  Product:
 *      use findroot(a)==findroot(b) to check whether a,b is in the same set.
 *
 *  Functions:
 *
 */


//Prerequisite
const int RANGE = 1e9;
int	parent[RANGE];
int rank[RANGE];    //i.e.  The depth of the tree.
bool PATHSPLITTING = true;

//[0, range) - the range of the case
void init(int range) {
    for(int i = 0;i < range;i++)    {
        parent[i] = i;
        rank[i] = 1;
    }
}

int findroot(int x) {
    if(PATHSPLITTING) {
        if(parent[x] == x)  return x;
        else return parent[x] = findroot(parent[x]);
    }
    else {
        if (parent[x] == x) return x;
        else {
            parent[x] = findroot(parent[x]);
            rank[parent[x]]++;
        }
        return parent[x];
    }
}

void merge(int a, int b) {
    a = findroot(a);
    b = findroot(b);
    if (a == b)	return;

    if (rank[a] > rank[b]) {
        parent[b] = a;
        rank[a] += rank[b];
    }
    else    {
        parent[a] = b;
        rank[b] += rank[a];
    }
}
