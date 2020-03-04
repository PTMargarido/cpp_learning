#include <string>
#include <list>
#include <type_traits>

template<typename T>
struct MyStruct
{
    std::string name;
    T id;
};

// C++11 implementation
template<typename T>
using MyList11 = std::list<T, MyStruct<T>>;

template<typename T>
class MyClass11{
    private:
        MyList11<T> list;
};

template<typename T>
using remove_const_t = typename std::remove_const<T>::type;


// C++98 implementation
template<typename T>
struct MyList98
{
   typedef std::list<T, MyStruct<T>> type;
};

template<typename T>
class MyClass98{
    private:
        typename MyList98<T>::type list;
};

int main()
{

}
