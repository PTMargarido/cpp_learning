#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;
int main()
{
    vector<int> vecMove({1,2,3,4,5,6,7,8});
    vector<int> vecDest;

    move(vecMove.begin(), vecMove.end(), back_inserter(vecDest));

    for (auto c: vecDest)
        cout << c << "\n";

    for (auto c: vecMove)
        cout << c << "\n";
}
