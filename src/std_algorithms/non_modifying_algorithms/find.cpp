#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // find
    cout << "--- std::find ---" << endl;
    vector<int> vecFind{1,2,3,4,6};
    auto findIt = find(vecFind.begin(), vecFind.end(), 4);
    cout << *findIt << endl;

    cout << "--- std::find_if ---" << endl;
    auto findIfIt = find_if(vecFind.begin(), vecFind.end(), [](int& value)
            {
                return value > 2;
            });
    cout << *findIfIt << endl;

    cout << "--- std::find_if_not ---" << endl;
    auto findIfNotIt = find_if_not(vecFind.begin(), vecFind.end(), [](int& value)
            {
                return value < 2;
            });
    cout << *findIfNotIt << endl;
    
}
