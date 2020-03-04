#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main ()
{
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
    
}
