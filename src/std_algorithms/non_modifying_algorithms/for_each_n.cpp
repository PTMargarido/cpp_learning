#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    int nComparison = 5;
    vector<int> vecForEach({1,2,3,4,5,6,7,1,2,3,4});
    // for_each_n
    cout << "--- std::for_each_n ---" << endl;
    for_each_n(vecForEach.cbegin(), 6, [nComparison](int value){ 
                if(nComparison > value)
                    cout << "Value " << value << " is less than " << nComparison << endl;
       });
    
}
