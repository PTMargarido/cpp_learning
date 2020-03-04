#include <iostream>

using namespace std;

class Singleton
{
    public:
        void setValue(int value)
        {
            m_Value = value;
        };

        int getValue()
        {
            return m_Value;
        };

        static Singleton& getInstance()
        {
            static Singleton instance;
            cout << "Address of Singleton: " << &instance << endl;
            return instance;
        };

        Singleton(Singleton const&) = delete;

        void operator=(Singleton const&) = delete;

    private:
        Singleton() {};
        int m_Value;
};

int main ()
{
    Singleton::getInstance().setValue(5);
    cout << Singleton::getInstance().getValue() << endl;
}
