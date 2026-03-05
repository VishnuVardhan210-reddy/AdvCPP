#include<iostream>
#include<stdexcept> 

int main() {
    try {
        std::cout << "started execution\n" ;
        // some code logic 
        throw std::runtime_error("avengers essemble");
    } catch (const std::runtime_error& e) {
        std::cout << "caught the excpetion" <<std::endl;
        std::cout <<e.what() << "\n";
    }
}