#include <iostream>
#include <algorithm>

using namespace std;

struct student{
    int math;
    int eng;
    int id;
}scores[1010];

bool byMath(student lhs, student rhs)   {
    if(lhs.math == rhs.math)
        return lhs.id < rhs.id;
    return lhs.math > rhs.math;
}

bool byEng(student lhs, student rhs)   {
    if(lhs.eng == rhs.eng)
        return lhs.id < rhs.id;
    return lhs.eng > rhs.eng;
}

bool byAll(student lhs, student rhs)    {
    if((lhs.math + lhs.eng) == (rhs.math + rhs.eng))
        return lhs.id < rhs.id;
    return (lhs.math + lhs.eng) > (rhs.math + rhs.eng);
}

bool byID(student lhs, student rhs) {
    return lhs.id < rhs.id;
}

int main()  {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    for(int i = 0;i < n;i++)
        cin >> scores[i].math;
    for(int i = 0;i < n;i++)
        cin >> scores[i].eng;
    for(int i = 0;i < n;i++)
        scores[i].id = i + 1;

    stable_sort(scores, scores + n, byMath);
    stable_sort(scores + x, scores + n, byEng);
    stable_sort(scores + x + y, scores + n, byAll);
    stable_sort(scores, scores + x + y + z, byID);

    for(int i = 0;i < x + y + z;i++)
        cout << scores[i].id << endl;

    cout << endl;

    return 0;
}