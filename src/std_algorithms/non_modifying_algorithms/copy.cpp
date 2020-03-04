#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // copy
    cout << "--- std::copy ---" << endl;

    vector<int> vecCopy1{2, 4, 6, 8, 10, 12, 14};
    vector<int> vecCopy2;

    copy(vecCopy1.begin(), vecCopy1.end(), back_inserter(vecCopy2));
    
    for (auto p: vecCopy2)
    {
        cout << p << endl;
    }
}
