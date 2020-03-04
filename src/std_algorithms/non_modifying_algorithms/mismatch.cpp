#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // mismatch
    cout << "--- std::mismatch ---" << endl;
    vector<int> vecMismatch1{1,2,3,4,5};
    vector<int> vecMismatch2{1,2,4,4,5};

    auto mismatchIt = mismatch(vecMismatch1.cbegin(), vecMismatch1.cend(), vecMismatch2.cbegin());
    cout << *mismatchIt.first << endl;
    
}
