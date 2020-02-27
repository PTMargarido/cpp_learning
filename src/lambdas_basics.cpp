#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int evaluateValue(int &value)
{
    int nValue = 5;
    if (value > nValue)
    {
        value = nValue;
    }
    return value;
};

int main ()
{
    int nValue = 10;
    vector<int> vecTest{1,2,20,40,50,10};
    vector<int> vec_test_transformed;
    
    // std::for_each with lambda applied to each element of the vector
    for_each(vecTest.begin(), vecTest.end(), [nValue](int& value)
    {
        if (value > nValue)
        {
            value = nValue;
        }
    });

    nValue = 5;

    // std::transform with function object applied to each element of the vector
    transform(vecTest.begin(), vecTest.end(), back_inserter(vec_test_transformed), &evaluateValue);

    nValue = 3;

    // std::transform with lambda applied to each element of the vector
    transform(vecTest.begin(), vecTest.end(), vec_test_transformed.begin(), [nValue](int& value) -> int
    {
        if (value > nValue)
        {
            value = nValue;
        }
        
    });

    for(auto p: vecTest)
        cout << p << endl;

    vector<string> vecString{"Hello","Friend"};
    vector<size_t> vecSizeStrings;
      
    transform(vecString.begin(), vecString.end(), back_inserter(vecSizeStrings), [](const string vecEntry)
    {
        return vecEntry.size();
    });

    for(auto p: vecSizeStrings)
        cout << p << endl;
   
}
