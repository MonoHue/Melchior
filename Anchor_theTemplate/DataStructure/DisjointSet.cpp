/*
 *  Disjoint Set
 *  Todo:   Implementations
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
 *          It will always attach the smaller tree to the bigger one.
 *          If you just need to MERGE two trees, this type will makes a tree with minimum depth.
 *      c.  Merge by Sequence
 *          It will always follow the instructions, attaching one tree to another.
 *          Notice that in some cases, this type will turn into a linked list.
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
 *      int parent[]
 *          parent[i] is i's parent (or root, if (a) is enabled).
 *      int rank[]
 *          The depth of the element in the tree. Root's depth is 1.
 *
 *  Functions:
 *  void init(int range)
 *      Initialize the parent[] and rank[]
 */


//Prerequisite
const int RANGE = 1e9;
//Product
int	parent[RANGE];
int rank[RANGE];    //i.e.  The depth of the tree.
//Switch
bool PATHSPLITTING = true;
bool MERGEBYRANK = true;

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
