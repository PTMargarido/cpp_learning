#include <tuple>
#include <iostream>
#include <string>
#include <cstdint>

enum class UserInfoFields : uint8_t
{
    Name = 0,
    Email = 1,
    Age = 2
};


template<typename T>
constexpr auto
ToUType(T enumerator) noexcept
{
    return static_cast<std::underlying_type_t<T>>(enumerator);
}


using UserInfo = std::tuple<std::string,std::string,std::size_t>;

int main()
{
    UserInfo uInfo{"hi", "hello", 5};
    std::cout << std::get<ToUType(UserInfoFields::Name)>(uInfo)
              << " "
              << std::get<ToUType(UserInfoFields::Email)>(uInfo)
              << " "
              << std::get<ToUType(UserInfoFields::Age)>(uInfo)
              << std::endl;
}
