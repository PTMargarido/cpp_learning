#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // adjacent_find    
    cout << "--- std::adjacent_find ---" << endl;
    vector<int> vecAdjacentFind{1,1,2,3,4,5,6,7,8,8,2,5,6};

    auto findAdjacentFind = adjacent_find(vecAdjacentFind.begin(), vecAdjacentFind.end());
    cout << distance(vecAdjacentFind.begin(), findAdjacentFind) << endl;

    // adjacent_find    
    cout << "--- std::adjacent_find with greater predicate ---" << endl;
    auto findAdjacentFindGreater = adjacent_find(vecAdjacentFind.begin(), vecAdjacentFind.end(), greater<int>());
    cout << distance(vecAdjacentFind.begin(), findAdjacentFindGreater) << endl;
}
