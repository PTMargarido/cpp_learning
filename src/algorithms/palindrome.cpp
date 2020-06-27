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
bool isPalindrome(const T& intPalindrome)
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
    string testStr = "abbaa";
    cout << isPalindrome<string>(testStr) << endl;
    int numberInt = 1222;
    cout << isPalindrome<int>(numberInt) << endl;
    numberInt = 1221;
    cout << isPalindrome<int>(numberInt) << endl;
    return 0;
}
