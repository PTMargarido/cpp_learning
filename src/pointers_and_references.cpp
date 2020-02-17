// ### References ### 

// In C++, it became possible to create references to objects.
// It is set by using the & operator after the type. It works as
// an alias of the variable that it is referencing to.


// ### Pointers ### 

// Pointers is a type that points to some object. Its value is the memory
// address of the variable that it pointing to. In C++11, it was added
// the weak_ptr, unique_ptr and the shared_ptr.
#include <iostream>

using namespace std;
int main()
{
    int nVar{5}; // Initializer List initialization, added in C++11
    int& nVarRef = nVar;
    int* nVarPoint = &nVar;

    cout << "Memory address of the variable nVar is " << &nVar << endl;
    cout << "Memory address of the reference to nVar (nVarRef) is " << &nVarRef << endl;
    cout << "Memory address of the pointer to nVar (nVarPoint) is " << &nVarPoint << endl;
    

    cout << "Value of the variable nVar is " << nVar << endl;
    cout << "Value of the reference to nVar (nVarRef) is " << nVarRef << endl;
    cout << "Value of the pointer to nVar (nVarPoint) is " << nVarPoint <<
            " and the content of nVarPoint is " << *nVarPoint << endl;
    
    return 0;
}
