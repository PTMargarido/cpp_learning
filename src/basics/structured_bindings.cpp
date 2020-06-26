#include <iostream>
#include <tuple>
#include <string>

using namespace std;

tuple<int, string> testStructuredBinding()
{
    return make_tuple<int, string>(42, "Hello World");
};

int main ()
{
    // C++ 17
    auto [number, str] = testStructuredBinding();
    cout << number << " " << str << endl;
}
