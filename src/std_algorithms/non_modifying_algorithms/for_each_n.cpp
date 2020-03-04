#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
    // for_each_n
    cout << "--- std::for_each_n ---" << endl;
    for_each_n(vecForEach.cbegin(), 1, [nComparison](int value){ 
                if(nComparison > value)
                    cout << "Value " << value << " is less than " << nComparison << endl;
       });
    
}
