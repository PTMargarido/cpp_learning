#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <vector>

class String 
{
    public:
        String() = default;

        String(const char* str)
        {
            m_Size = strlen(str);
            m_Data = new char[m_Size];

            memcpy(m_Data, str, m_Size);
            std::cout << "Constructing String object " << m_Data << "\n";
        }

        String(const String& other)
        {
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
        }

        String(String&& other)
        {
            m_Size = other.m_Size;
            m_Data = other.m_Data;

            std::cout << "Moving m_Data " << other.m_Data << " from String object by assignment operator " << &other.m_Data << " to " << &m_Data <<  "\n";

            other.m_Size = 0;
            other.m_Data = nullptr;
        }

        String& operator= (String&& other)
        {

            if (this != &other)
            {
                delete[] m_Data;

                m_Size = other.m_Size;
                m_Data = other.m_Data;

                std::cout << "Moving m_Data" << other.m_Data << " from String object by assignment operator " << &other.m_Data << " to " << &m_Data <<  "\n";

                other.m_Size = 0;
                other.m_Data = nullptr;
            }

            return *this;
        }

        String& operator+ (String& other)
        {
            int sizeHold = m_Size;
            char* strHold = new char[m_Size];
            memcpy(strHold, m_Data, m_Size);

            delete[] m_Data;

            m_Data = new char[m_Size + other.m_Size];

            m_Size += other.m_Size;

            memcpy(m_Data, strHold, sizeHold);
            memcpy(m_Data + sizeHold, other.m_Data, other.m_Size);

            delete[] strHold;

            return *this;
        }

        ~String()
        {
            delete[] m_Data;
        }

        void Print()
        {
            for (int i = 0; i < m_Size; i++)
                std::cout << m_Data[i];

            std::cout << " ";

        }

        char* m_Data;
        size_t m_Size;
};

int main()
{
    std::string phrase("I like apples and strawberries");

    std::vector<String> vecStrings;

    std::istringstream iss(phrase);
    std::string A;


    while (iss >> A)
    {
        vecStrings.push_back(String(A.c_str()));
    }

    for (auto c: vecStrings)
        c.Print();

    String str1("Pedro ");
    String str2("Sara ");

    String str3 = std::move(str1 + str2);

    str3.Print();
};
