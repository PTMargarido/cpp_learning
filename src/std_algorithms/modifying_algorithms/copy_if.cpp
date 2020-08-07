#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;
int main()
{
    vector<int> vecCopyIf({1,2,3,4,5,6,7,8});
    vector<int> vecDest;

    copy_if(vecCopyIf.cbegin(), vecCopyIf.cend(), back_inserter(vecDest), [](const int e){
        return e % 2;
    });

    for (auto c: vecDest)
        cout << c << "\n";
}
