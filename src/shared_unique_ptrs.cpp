#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class IPrint
{
    public:
    virtual void print() const = 0;
};

class Xerox : public IPrint
{
    public:
    void print() const override
    {
        cout << "I'm a Xerox printer" << endl;
    };

    string model;

    ~Xerox()
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
