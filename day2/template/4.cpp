#include <iostream>

void print() {
    std::cout << "End\n";
}

template <typename T, typename... Args> 
void print(T first, Args... rest){
    std::cout << first << std::endl;
    print(rest...);
}

int main() 
{
    print(10, 20, 30, "hello");
    std::cout << "------------------" << std::endl;
    print(11, 22);

}

