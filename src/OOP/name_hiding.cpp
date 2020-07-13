#include <iostream>
#include <string>

using namespace std;

class Person
{
    public:
        Person(){};
        virtual void GetName(int arg1);
        void GetName(int arg1, int arg2);
};

void Person::GetName(int arg1, int arg2)
{ 
    cout << "THREE! \n";
} 

void Person::GetName(int arg1)
{ 
    cout << "FIVE! \n";
} 

class Child : public Person
{
    public:
        Child(){};
    
        using Person::GetName;
        void GetName(int arg1) override;
};

void Child::GetName(int arg1) 
{
    cout << "FOUR \n";
};

int main()
{
    Child testObj = Child();

    testObj.GetName(5, 5);
    testObj.GetName(5);
}
