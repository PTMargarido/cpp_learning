#include <iostream>

using namespace std;
// ## Usage of static keyword ###

// ### File ###

// When a variable is declared with static on a file,
// it means, that variable will be "private" to that translation unit.
// (other translation units will not be aware of this symbol)

static int nFileVar = 5;

// ### Struct/Classes scope ###

// When a variable is declared with static on a class or a struct,
// it means, that variable will be shared between all objects of that class or 
// struct.

struct Foo
{
    int GetnVar() { return nVar; }
    Foo() { nVar++; }
    //static int nVar; // Before C++17, nVar had to be initialized outside class
    inline static int nVar = 0; // After C++17 it is possible to initialize class static members in the declaration
};

// int Foo::nVar = 0;

// ### Local scope ###

// When a variable is declared with static on a local scope, it means,
// that variable will have the lifetime of the program, but only accessible 
// in that scope.

int fooFunc()
{
    static int nVar;
    nVar++;
    return nVar;
}

int main ()
{

    cout << "Static in Class Scope" << endl;
    Foo foo_one;
    cout << foo_one.GetnVar() << endl;
    Foo foo_two;
    cout << foo_two.GetnVar() << endl;
    Foo foo_three;
    cout << foo_three.GetnVar() << endl;
    Foo foo_four;
    cout << foo_four.GetnVar() << endl;

    cout << "Static in Local Scope" << endl;
    cout << fooFunc() << endl;
    cout << fooFunc() << endl;
    cout << fooFunc() << endl;
    cout << fooFunc() << endl;
    return 0;
}



