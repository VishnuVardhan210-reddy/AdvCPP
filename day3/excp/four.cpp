#include<iostream>
#include<stdexcept> 
#include<fstream>

int main() {
    try {
        std::vector<int> v = {10, 20, 30};
        std::cout << v.at(11);
        std::cout<<"no exception\n";

    } catch (const std::out_of_range& e) {
        std::cout << "exception was raised\n";
        std::cout <<e.what() << "\n";
    }
}