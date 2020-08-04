#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    vector<int> vecCount({1,2,4,5,6,1,2,4,6,10,22});
    // count_if
    cout << "--- std::count_if ---" << endl;
    auto nCount = count_if(vecCount.cbegin(), vecCount.cend(), [](int value){
                if(value >= 8)
                    return true;
                else
                    return false;
            });

    cout << nCount << endl;
    
}
