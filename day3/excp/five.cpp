#include<iostream>
#include<stdexcept> 

struct Sample {
    Sample() { std::cout << "constructor\n";}
    ~Sample() { std::cout << "destructor\n";}
};
void f() {
    Sample s;
    std::cout << "In f(), about to throw..\n";
    throw std::runtime_error("boom");
}
int main() {
    try {
        f();
    } catch (const std::exception& e) {
        std::cout <<"caught: " << e.what() << "\n";
    }
}