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
        cout << p << endl;

    // copy_if
    cout << "--- std::copy_if ---" << endl;
    vector<int> vecCopyIf;
    copy_if(vecCopy1.cbegin(), vecCopy1.cend(), back_inserter(vecCopyIf), [](int value){
                return !(value % 3);
            });
    
    for (auto p: vecCopyIf)
        cout << p << endl;

    // copy_n
    cout << "--- std::copy_n ---" << endl;
    vector<int> vecCopyN;
    copy_n(vecCopy1.cbegin(), 4, back_inserter(vecCopyN));
    
    for (auto p: vecCopyN)
        cout << p << endl;

    // copy_backwards
    cout << "--- std::copy_backwards ---" << endl;
    vector<int> vecCopyBackwards(8);
    copy_backward(vecCopy1.begin(), vecCopy1.end(), vecCopyBackwards.end());
    
    for (auto p: vecCopyBackwards)
        cout << p << endl;
}
