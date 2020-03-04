#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // all_of
    cout << "--- std::all_of ---" << endl;

    vector<int> vecAllOf{2, 4, 6, 8, 10, 12, 14};
    if (all_of(vecAllOf.cbegin(), vecAllOf.cend(), [](int value){ return !(value % 2); }))
    {
        cout << "All number are even" << endl;
    }
    else
    {
        cout << "At least one number is odd" << endl;
    }
    
}
