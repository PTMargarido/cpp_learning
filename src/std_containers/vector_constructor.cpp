#include <functional>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class A
{
    public:
        A()
        {
            cout << "A Constructor" << endl;
        };
};

class B: public A
{
    public:
        B()
        {
            cout << "B Constructor without int" << endl;
        };
        B(int value)
        {
            cout << "B Constructor with int: " << value << endl;
        };
};

template<typename T>
function<A*(void)> funcFactory(const int value)
{
    return [value]() -> A* {
         return new T(value);
    };
};

int main ()
{
    vector<function<A*()>> vecOfFuncPointers;

    vecOfFuncPointers.emplace_back(funcFactory<B>(5));
    vecOfFuncPointers.emplace_back(funcFactory<B>(6));
    vecOfFuncPointers.emplace_back(funcFactory<B>(7));

    for (auto p: vecOfFuncPointers)
        p();
}
