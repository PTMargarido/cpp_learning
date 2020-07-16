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
            std::cout << "Copying String object " << m_Data << "\n";
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

        String operator+ (String& other)
        {
            String res;

            res.m_Data = new char[m_Size + other.m_Size];

            res.m_Size = m_Size + other.m_Size;

            memcpy(res.m_Data, m_Data, m_Size);
            memcpy(res.m_Data + m_Size, other.m_Data, other.m_Size);
            return res;
        }

        String& operator+= (String& other)
        {
            int sizeHold = m_Size;
            char* strHold = new char[m_Size];

            memcpy(strHold, m_Data, m_Size);

            delete[] m_Data;

            m_Data = new char[m_Size + other.m_Size];
            m_Size = m_Size + other.m_Size;

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

            std::cout << "\n";

        }

        char* m_Data;
        size_t m_Size;
};

int main()
{
    std::string phrase("I like apples and strawberries");

    std::vector<String> vecStrings;
    vecStrings.resize(5);

    std::istringstream iss(phrase);
    std::string A;


    while (iss >> A)
    {
        vecStrings.push_back(String(A.c_str()));
    }

    std::cout << "------\n";


    String strA("Hi");
    String strB(" there");
    String strC;

    strC = strA + strB;

    strC.Print();
    strA.Print();
    strB.Print();

    strA += strB;

    strA.Print();
    strB.Print();


};
