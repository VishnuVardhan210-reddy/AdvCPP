#include <iostream>
struct sample
{
    int x = 100;
};
template<typename T>
void print(T value)
{
    std::cout << value << std::endl;
}
int main() 
{
    sample st;
    print(10);          //works
    print("hello");     //works
    print(st);          //compile time error 
}

