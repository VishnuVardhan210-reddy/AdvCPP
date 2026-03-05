#include <iostream>

template <typename T> 
T function_name (T arg1, T arg2) {
    // some logic with arg1 & arg2 
    return arg1 + arg2;
}
template <typename T> 
T function_name (T arg1, T arg2, T arg3) {
    // some logic with arg1 & arg2 
    return arg1 + arg2;
}
std::string function_name 
        (std::string arg1, std::string arg2) {
        return "please don't add strings";
}

int main() 
{
    std::cout << function_name(10, 20) << std::endl;
    std::cout << function_name("hi", "hello") << std::endl;
}

