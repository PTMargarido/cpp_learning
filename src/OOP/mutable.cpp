#include <iostream>
#include <string>

using namespace std;

class Person
{
    public:
    explicit Person(const string& name) : 
        name(name), 
        numRetrievedTimes(0)
    {
    };

    string GetName() const 
    { 
        numRetrievedTimes++;
        return name; 
    } 

    private:
    string name;
    mutable int numRetrievedTimes;
};


int main()
{
    string personName ("Sara");
    Person personObj(personName);

    string strName = personObj.GetName();

    cout << strName << endl;

}
