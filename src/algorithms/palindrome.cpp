#include <string>
#include <iostream>

using namespace std;

bool verifyPalindrome(const string& strPalindrome)
{
    size_t strEnd = strPalindrome.size() - 1;
    for (auto& c: strPalindrome)
    {
        if (c != strPalindrome.at(strEnd))
            return false;

        if (strEnd == strPalindrome.size()/2)
            break;

        strEnd--;
    }
    return true;

}

template <typename T>
constexpr bool isPalindrome(const T& intPalindrome)
{
    return verifyPalindrome(to_string(intPalindrome));
}

template<>
bool isPalindrome(const string& strPalindrome)
{
    return verifyPalindrome(strPalindrome);
}

template<>
bool isPalindrome(const double& strPalindrome) = delete;

int main()
{
    constexpr auto testStr =  "abba";
    cout << isPalindrome<string>(testStr) << endl;
    constexpr int numberInt = 1221;
    cout << isPalindrome<int>(numberInt) << endl;
    return 0;
}
