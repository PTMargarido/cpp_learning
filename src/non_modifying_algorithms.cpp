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

    // none_of
    cout << "--- std::none_of ---" << endl;

    long unsigned int nChars = 4;
    string strMatch;

    vector<string> vecNoneOfString{"pig", "dog", "cow", "bird"};
    if (none_of(vecNoneOfString.cbegin(), vecNoneOfString.cend(), [nChars, &strMatch](string value){
             if (value.size() >= nChars)
             {
                strMatch = value;
                return true;
             } 
             else
                 return false;}))
    {
        cout << "No string has " << nChars << " characters" << endl;
    }
    else
    {
        cout << "There is a word " << strMatch << " with at least " <<
            nChars << endl;
    }

    // any_of
    cout << "--- std::any_of ---" << endl;
    int nDivisor = 8;
    int nValue = 0;

    vector<int> vecAnyOf{2, 4, 6, 8, 10, 12, 14};
    if (any_of(vecAnyOf.cbegin(), vecAnyOf.cend(), [&nValue, nDivisor](int value){ 
                if(!(value % nDivisor))
                {
                    nValue = value;
                    return true; 
                }
                else
                    return false;
       }))
    {
        cout << "At least one value  " << nValue << " is divisable by " << nDivisor << endl;
    }

    // for_each
    cout << "--- std::for_each ---" << endl;
    int nComparison = 5;
    vector<int> vecForEach{2, 4, 6, 8, 10, 12, 14};
    for_each(vecForEach.cbegin(), vecForEach.cend(), [nComparison](int value){ 
                if(nComparison > value)
                    cout << "Value " << value << " is less than " << nComparison << endl;
       });

    // for_each_n
    cout << "--- std::for_each_n ---" << endl;
    for_each_n(vecForEach.cbegin(), 1, [nComparison](int value){ 
                if(nComparison > value)
                    cout << "Value " << value << " is less than " << nComparison << endl;
       });

    // count
    cout << "--- std::count ---" << endl;
    vector<int> vecCount{2, 4, 6, 8, 8, 8, 14};
    int nCount = count(vecCount.cbegin(), vecCount.cend(), 8);
    cout << nCount << endl;

    // count_if
    cout << "--- std::count_if ---" << endl;
    nCount = count_if(vecCount.cbegin(), vecCount.cend(), [](int value){
                if(value >= 8)
                    return true;
                else
                    return false;
            });

    cout << nCount << endl;

    // mismatch
    cout << "--- std::mismatch ---" << endl;
    vector<int> vecMismatch1{1,2,3,4,5};
    vector<int> vecMismatch2{1,2,4,4,5};

    auto mismatchIt = mismatch(vecMismatch1.cbegin(), vecMismatch1.cend(), vecMismatch2.cbegin());
    cout << *mismatchIt.first << endl;
} 
