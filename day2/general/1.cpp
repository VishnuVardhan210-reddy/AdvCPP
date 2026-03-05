#include<type_traits>
#include<iostream>

int main() {
    std::cout << std::is_integral<int>::value << std::endl;
    std::cout << std::is_integral<double>::value << std::endl;
    std::cout << std::is_integral_v<double> << std::endl;  //C++17
}

template<typename T>
void process (T value) 
{
    if constexpr(std::is_integral_v<T>) 
        std::couty << "integral type\n";
    else
        std::cout << "non integral type\n";
}