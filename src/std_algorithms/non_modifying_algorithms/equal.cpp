#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // equal
    cout << "--- std::equal ---" << endl;
    vector<int> vecEqual1{1,2,3,4,5};
    vector<int> vecEqual2{0,2,3,4,5};

    auto bEqual = equal(vecEqual1.cbegin(), vecEqual1.cend(), vecEqual2.cbegin());
    cout << bEqual << endl;
    
}
