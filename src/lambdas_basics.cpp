#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
    int nValue = 10;
    vector<int> vecTest{1,2,20,40,50,10};

    for_each(vecTest.begin(), vecTest.end(), [nValue](int& value)
    {
        if (value > nValue)
        {
            value = nValue;
            cout << value << endl;
        }
    });
    
    for (auto p: vecTest)
    {
        cout << p << endl;
    }
}
