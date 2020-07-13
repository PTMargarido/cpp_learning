#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person
{
    public:

        Person(){
            cout << "Person constructor has been called \n";
        };

        virtual ~Person() {
            cout << "Person destructor has been called \n";
        }
};

class Child : public Person
{
    public:

        Child(){
            cout << "Child constructor has been called \n";
        };

        ~Child () {
            cout << "Child destructor has been called \n";
        }
};


int main()
{
    Person* testObj =  new Child();

    delete testObj;
}
