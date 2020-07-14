#include <iostream>
#include <string.h>

class String 
{
    public:
       String() = default;

       String(const char* str)
       {
           m_Size = strlen(str);
           m_Data = new char[m_Size];

           std::cout << "Constructing String object " << &m_Data << "\n";
           memcpy(m_Data, str, m_Size);
       }

       String(const String& other)
       {
           m_Size = other.m_Size;
           m_Data = new char[m_Size];

           std::cout << "Copying String object " << &m_Data << "\n";
           memcpy(m_Data, other.m_Data, m_Size);
       }

       String(String&& other)
       {
           m_Size = other.m_Size;
           m_Data = other.m_Data;

           std::cout << "Moving m_Data from String object " << &other.m_Data << " to " << &m_Data <<  "\n";

           other.m_Size = 0;
           other.m_Data = nullptr;
       }

       ~String()
       {
           std::cout << "Destructing String object " << &m_Data << "\n";
           delete[] m_Data;
       }

       void Print()
       {
           std::cout << m_Data << "\n";
       }

       char* m_Data;
       size_t m_Size;
};

class stringHolder
{
    public:
    stringHolder(String&& str):
        m_strHold(std::move(str))
    {
        std::cout << "Constructing stringHolder object \n";
    }

    private:
        String m_strHold;
};

int main()
{
    stringHolder strHold("Pedro");
}
