#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // search_n
    cout << "--- std::search_n ---" << endl;
    vector<int> vecSearch{1,1,2,3,4,5,6,7,8,8,2,5,6};

    auto searchInt = search_n(vecSearch.cbegin(), vecSearch.cend(), 3, 8) != vecSearch.cend() ? true : false;
    cout << searchInt << endl;

    // search
    cout << "--- std::search ---" << endl;
    string strSearch = "Hello Pedro, I am Pedro";
    string strToSearch = "Perd";

    auto strSearchIt = search(strSearch.cbegin(), strSearch.cend(), strToSearch.cbegin(), strToSearch.cend()) != strSearch.cend() ? true : false;
    cout << strSearchIt << endl;
}
