#include <iostream>
#include <vector>

using namespace std;

class IPrint
{
    public:
    virtual void print() const = 0;
};


class HP : public IPrint
{
    void print() const override
    {
        cout << "I'm a HP printer" << endl;
    };
};

class Xerox : public IPrint
{
    void print() const override
    {
        cout << "I'm a Xerox printer" << endl;
    };
};

int main ()
{
    vector<IPrint*> vecPrint;

    vecPrint.emplace_back(new Xerox());
    vecPrint.emplace_back(new HP());
    
    for (auto &it : vecPrint)
        it->print();
}
