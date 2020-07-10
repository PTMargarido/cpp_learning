#include <iostream>
#include <string>

void PrintNameLvalueRef(const std::string& name)
{

}

void PrintNameLvalueRef(std::string& name)
{

}

// this function overload will have precedence for
// rvalues, even though const string& can also accept
// rvalues
void PrintNameRvalueRef(std::string&& name)
{

}

void PrintNameRvalueRef(const std::string& name)
{

}

void PrintNameWorking(const std::string& name)
{

}

int main()
{
    // "Pedro" is a rvalue since it has no storage
    // firstName is a lvalue since it has storage
    std::string firstName = "Pedro";

    // "Margarido" is a rvalue since it has no storage
    // lastName is a lvalue since it has storage
    std::string lastName = "Margarido";

    // firstName + lastName is a temporary constructed string (rvalue)
    // fullName is a lvalue
    std::string fullName = firstName + lastName;


    // Works since it takes a reference to a lvalue 
    PrintNameLvalueRef(fullName);

    // Works since it takes a reference to a lvalue 
    PrintNameWorking(fullName);

    // Does not work since it takes a reference to a rvalue 
    PrintNameRvalueRef(fullName);

    // Does not work since it can not take a reference to
    // a rvalue
    PrintNameLvalueRef(firstName + lastName);

    // Works since it creates a temporary object and then assigns it 
    // to const std::string&
    PrintNameWorking(firstName + lastName);

    // Works since it takes a rvalue referece 
    PrintNameRvalueRef(firstName + lastName);

}
