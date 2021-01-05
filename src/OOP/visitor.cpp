#include <variant>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Visitor
{
public:
    string operator()(string& s)
    {
        return s;
    }

    template<typename T>
    string operator()(T& s)
    {
        return to_string(s);
    }
};

int main ()
{
    variant<string, double, int> var;

    var = "string";
    cout << visit(Visitor{}, var) << endl;

    var = 5;
    cout << visit(Visitor{}, var) << endl;

    var = 5.0;
    cout << visit(Visitor{}, var) << endl;
}
