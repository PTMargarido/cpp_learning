#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // count_if
    cout << "--- std::count_if ---" << endl;
    nCount = count_if(vecCount.cbegin(), vecCount.cend(), [](int value){
                if(value >= 8)
                    return true;
                else
                    return false;
            });

    cout << nCount << endl;
    
}
