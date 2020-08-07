#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;
int main()
{
    vector<int> vecCopyBackward({1,2,3,4,5,6,7,8});
    vector<int> vecDest;
    vecDest.resize(15);

    copy_backward(vecCopyBackward.cbegin(), vecCopyBackward.cend(), vecDest.end());

    for (auto c: vecDest)
        cout << c << "\n";
}