#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class IPrint
{
    public:
    virtual void print() const = 0;

    // Base class must have virtual destructor in order to call derived class
    // destructor. With 'virtual ~IPrint()', ~Xerox() is invoked. Without virtual
    // it is not.
    virtual ~IPrint()
    {
        cout << "Destructor IPrint: " << this << endl;
    };
};

class Xerox : public IPrint
{
    public:
    void print() const override
    {
        cout << "I'm a Xerox printer" << endl;
    };

    string model;

    ~Xerox() override
    {
        cout << "Destructor Xerox: " << this << endl;
    }

    Xerox(Xerox&& other)
    {
        cout << "Move Operator from: " << &other << endl;
        cout << "Move Operator to: " << this << endl;
    }

    Xerox(string str) : model(str)
    {
        cout << "Constructor Xerox: " << this << endl;
    }
};

int main ()
{
    {
        vector<shared_ptr<IPrint>> vecPrint;

        vecPrint.emplace_back(shared_ptr<Xerox>(new Xerox("XEROX2500")));
        
        for (auto &it : vecPrint)
        {
            cout << "Address original: " << &(*it) << endl;
        }
    }

    cout << "--------------" << endl;

    {
        vector<unique_ptr<IPrint>> vecPrint;

        vecPrint.emplace_back(unique_ptr<Xerox>(new Xerox("XEROX2500")));
        
        for (auto &it : vecPrint)
        {
            cout << "Address original: " << &(*it) << endl;
        }
    }

    cout << "--------------" << endl;
}
