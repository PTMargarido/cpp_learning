#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // any_of
    cout << "--- std::any_of ---" << endl;
    int nDivisor = 8;
    int nValue = 0;

    vector<int> vecAnyOf{2, 4, 6, 8, 10, 12, 14};
    if (any_of(vecAnyOf.cbegin(), vecAnyOf.cend(), [&nValue, nDivisor](int value){ 
                if(!(value % nDivisor))
                {
                    nValue = value;
                    return true; 
                }
                else
                    return false;
       }))
    {
        cout << "At least one value  " << nValue << " is divisable by " << nDivisor << endl;
    }

    // for_each
    cout << "--- std::for_each ---" << endl;
    int nComparison = 5;
    vector<int> vecForEach{2, 4, 6, 8, 10, 12, 14};
    for_each(vecForEach.cbegin(), vecForEach.cend(), [nComparison](int value){ 
                if(nComparison > value)
                    cout << "Value " << value << " is less than " << nComparison << endl;
       });
    
}
