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

} 
