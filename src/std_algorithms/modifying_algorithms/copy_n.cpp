#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;
int main()
{
    vector<int> vecCopyN({1,2,3,4,5,6,7,8});
    vector<int> vecDest;
    vecDest.resize(3);
    copy_n(vecCopyN.begin(), 3, vecDest.begin());

    for (auto c: vecDest)
        cout << c << "\n";
}
