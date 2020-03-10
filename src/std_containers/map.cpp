#include <functional>
#include <map>
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
        void print()
        {
            cout << "Print function" << endl;
        };
        B()
        {
            cout << "B Constructor without int" << endl;
        };
        B(int value)
        {
            cout << "B Constructor with int: " << value << endl;
        };
};

typedef map<string, A*> MapCreator1;
typedef map<string, A*(*)()> MapCreator2;

template<typename T>
A* CreateInstance()
{
    cout << "Invoked CreateInstance without int" << endl;
    return new T();
};

template<typename T, typename K>
A* CreateInstance(K value)
{
    cout << "Invoked CreateInstance with int" << endl;
    return new T(value);
};

int g_Value = 0;
template<typename T>
auto lambdaFunc = [g_Value]() -> A*
{
    return new T(g_Value);
};

template<typename T>
function<A*(void)> funcFactory(const int value)
{
    return [value]() -> A* {
         return new T(value);
    };
};
    

typedef map<string, function<A*()>> MapCreator3;

int main ()
{
    cout << "--- Constructor called when adding object ---" << endl;
    MapCreator1 mapOfObjects;
    mapOfObjects.emplace("B", CreateInstance<B>(1));

    cout << "--- Constructor explicitly called when invoking map by key ---" << endl;
    MapCreator2 mapOfObjects2;
    mapOfObjects2.emplace("B", &CreateInstance<B>);
    mapOfObjects2["B"]();

    cout << "--- Constructor explicitly called when invoking map by key with lambda ---" << endl;
    MapCreator2 mapOfObjects3;
    mapOfObjects3.emplace("B", lambdaFunc<B>);
    g_Value = 2;
    mapOfObjects3.emplace("C", lambdaFunc<B>);
    g_Value = 3;
    mapOfObjects3.emplace("D", lambdaFunc<B>);

    mapOfObjects3["B"]();
    mapOfObjects3["C"]();
    mapOfObjects3["D"]();

    cout << "--- Constructor explicitly called when invoking map by key with lambda and std::function ---" << endl;
    MapCreator3 mapOfObjects4;

    mapOfObjects4.emplace("B", funcFactory<B>(5));
    mapOfObjects4.emplace("C", funcFactory<B>(6));
    mapOfObjects4.emplace("D", funcFactory<B>(7));

    mapOfObjects4["B"]();
    mapOfObjects4["C"]();
    mapOfObjects4["D"]();
}
