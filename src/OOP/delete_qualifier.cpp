#include <iostream>

using namespace std;

int factorial(double value) = delete;

int factorial(int value)
{
    if (value == 1)
        return value;

    return (value * factorial(value - 1));
}

int main()
{
    auto x = factorial(5);
    cout << x << endl;
    cout << "--------" << endl;
    auto z = factorial(5.5f);
    cout << z << endl;
    cout << "--------" << endl;
}
