#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // count
    cout << "--- std::count ---" << endl;
    vector<int> vecCount{2, 4, 6, 8, 8, 8, 14};
    int nCount = count(vecCount.cbegin(), vecCount.cend(), 8);
    cout << nCount << endl;
    
}
