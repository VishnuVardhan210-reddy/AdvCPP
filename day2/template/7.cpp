#include <iostream>
#include<type_traits>
#include<utility>       // std::declval
struct sample
{
    int x = 100;
};
template<typename T, typename = void>
struct is_ostreamable : std::false_type {};

template<typename T>
struct is_ostreamable<T,
    std::void_t<decltype(std::declval<std::ostream&>() << std::declval<const T&>())>
> : std::true_type { };
//overload 1
template<typename T>
std::enable_if_t<is_ostreamable<T>::value, void>
print(const T& value)
{
    std::cout << value << "\n";
}
//overload 2
template<typename T>
std::enable_if_t<!is_ostreamable<T>::value, void>
print(const T&)
{
    std::cout << "Not printable type\n";
}

int main()
{
    print(10);          // uses ostreamable overload
    print(3.14);        // uses ostreamable overload

    sample np;
    print(np);          // uses fallback overload, program still compiles
}

