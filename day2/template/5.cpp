#include <iostream>
#include <utility> 

void process(int& x) {
    std::cout << "Lvalue reference\n";
}
void process(int&& x) {
    std::cout << "Rvalue reference\n";
}

template <typename T> 
void forwarder(T&& arg){
    process(std::forward<T>(arg));
}

int main() 
{
    int a = 10;
    forwarder(a);
    std::cout << "------------------" << std::endl;
    forwarder(20);

}

