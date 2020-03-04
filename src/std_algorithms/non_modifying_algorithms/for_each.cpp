#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // for_each
    cout << "--- std::for_each ---" << endl;
    int nComparison = 5;
    vector<int> vecForEach{2, 4, 6, 8, 10, 12, 14};
    for_each(vecForEach.cbegin(), vecForEach.cend(), [nComparison](int value){ 
                if(nComparison > value)
                    cout << "Value " << value << " is less than " << nComparison << endl;
       });
    
}
